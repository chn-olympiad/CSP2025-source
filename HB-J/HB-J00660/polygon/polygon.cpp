#include<bits/stdc++.h>
using namespace std;
string s;
int a[5005],a1[5005],n;
long long cnt;
void f(int x,int id){
	cnt%=998244353;
	if(id>3){
		int h=0,da=0;
		for(int j=1;j<id;j++){
			da=max(da,a1[j]);
			h+=a1[j];
		}
		if(h>da*2){
			cnt++;
		}
	}
	if(id==n+1||x==n+1)return;
	for(int i=x;i<=n;i++){
		a1[id]=a[i];
		f(i+1,id+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(1,1);
	cout<<cnt%998244353;
	return 0;
}
