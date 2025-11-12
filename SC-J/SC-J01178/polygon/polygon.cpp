#include<bits/stdc++.h>
using namespace std;
int a[5050],ans,n;
void f(int mx,int l,int x){
	if(x>n) return;
	if(l>mx*2) ans++;
	f(max(mx,a[x+1]),l+a[x+1],x+1);
	f(mx,l,x+1);
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0,0,0);
	cout<<ans;
	return 0;
}