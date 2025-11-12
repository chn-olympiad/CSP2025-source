#include<bits/stdc++.h>
using namespace std;
int a[505],bj[505],ans=0,n,m;
string b;
void f(int x,int y){
	if(x==n+1){
		if(y>=m) ans++;
		ans=ans%998244353;
		return;
	}
	for(int c=1;c<=n;c++){
		if(bj[c]==1) continue;
		bj[c]=1;
		if(x-1-y<a[c]&&b[x-1]=='1') f(x+1,y+1);
		else f(x+1,y);
		bj[c]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	for(int c=1;c<=n;c++){
		cin>>a[c];
	}
	f(1,0);
	cout<<ans;
	return 0;
}
