#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
long long ans;
void f(int l,long long num,int maxn,int xuan)
{
//	cout<<num<<' '<<xuan<<' '<<l<<endl;
	if(l>n)
	{
		if( ( num > (maxn*2) ) && xuan>=3) ans++;
		return;
	}
	f(l+1,num,maxn,xuan);
	f(l+1,num+a[l],max(maxn,a[l]),xuan+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	f(1,0,0,0);
	
	cout<<ans;
	return 0;
}
