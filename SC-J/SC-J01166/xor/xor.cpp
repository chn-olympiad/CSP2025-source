#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll n,k,a[1145140],b[1145140],ans;
ll xoor(ll x,ll y)
{
	ll ans=0,t[250],i=0;
//	cout<<"运算 "<<x<<" xor "<<y<<endl;
	while(x!=0||y!=0)
	{
		i++;
		ll l=x%2,r=y%2;
//		cout<<x<<" "<<y<<endl;
//		cout<<l<<" "<<r<<endl;
		if(l+r==1) t[i]=1;
		else t[i]=0;
//		cout<<t[i]<<endl<<endl;
		x/=2;
		y/=2;
	}
	for(int j=i;j>0;j--)
	{
//		cout<<i<<" "<<t[i]<<" "<<endl;
		ans=ans*2+t[j];
	}
//	cout<<endl;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<xoor(1,3);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		ll pre=0,j=i; 
		while(j<=n)
		{
			pre=xoor(pre,a[j]);
//			cout<<pre<<" ";
			if(pre==k)
			{
//				cout<<i<<" "<<j<<" ";
				b[i]=1;
				b[i]+=b[j+1];
//				cout<<b[i]<<endl;
				break;
			}
			j++;
		}
		b[i]=max(b[i],b[i+1]);
//		cout<<endl;
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
//	cout<<endl;
	cout<<b[1];
	return 0;
}
//freopen别忘了 
//感觉差不多11个点，多了要超时。orz orz orz orz 多给几个点吧！！
//100+100+50？+0=250？ 
//noooo 没有单调性！！！用不了二分！！！ 
//pre也没用…… 
//难道真的只能超时了吗？？？
//饿啊，我命由天不由我啊啊啊
//去年差5分省一的仇难道不报了吗？？？ 
//算了，下一题吧 