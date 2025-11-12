#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;cin.tie(0)->sync_with_stdio(false);
	cin>>a;
	int h[a+1];
	for(int i=1;i<=a;i++)cin>>h[i];
	for(int i=1;i<(1<<a);i++)
	{int m=0,k=0,cnt=0;
	for(int p=a;p>0;p--)
	{if((i>>(p-1))&1){
		++cnt;k+=h[p];m=max(m,h[p]);
	}}
	if(cnt>=3&&k>2*m)++ans;
	ans%=998244353;}
	cout<<ans;
	return 0;
}
