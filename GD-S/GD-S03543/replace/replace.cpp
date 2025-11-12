#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1024759811;
string s1[200005],s2[200005];
int num1[200005],num2[200005];
int fr1[200005],fr2;
map<int,int> cnt;
int fpow(int n,int m)
{
	int ans=1;
	while(m)
	{
		if(m%2) (ans*=n)%=mod;
		(n*=n)%=mod;
		m/=2;
	}
	return ans;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,q,flag=1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int flag1=0,flag2=0,l1,l2;
		for(int j=0;j<s1[i].length();j++)
		{
			num1[i]=(num1[i]*27+s1[i][j])%mod;
			if(s1[i][j]!='a')
			{
				if(s1[i][j]=='b') flag1++,l1=j;
				else flag=0;
			}
		}
		for(int j=0;j<s2[i].length();j++)
		{
			if(s2[i][j]!='a')
			{
				if(s2[i][j]=='b') flag2++,l2=j;
				else flag=0;
			}
			num2[i]=(num2[i]*27+s2[i][j])%mod;
		}
		if(flag1!=1||flag2!=1) flag=0;
		else cnt[l1-l2+5000000]++;
	}
	string t1,t2;
	int flagg=1;
//	if(flag)
//	{
//		while(q--)
//		{
//			cin>>t1>>t2;
//			int flag1=0,flag2=0,l1,l2;
//			for(int j=0;j<t1.length();j++)
//			{
//				if(t1[j]!='a')
//				{
//					if(t1[j]=='b') flag1++,l1=j;
//					else flagg=0;
//				}
//			}
//			for(int j=0;j<t2.length();j++)
//			{
//				if(t2[j]!='a')
//				{
//					if(t2[j]=='b') flag2++,l2=j;
//					else flagg=0;
//				}
//			}
//			if(flag1!=1||flag2!=1) flagg=0;
//			if(!flagg) break;
//			cout<<cnt[l1-l2+5000000]<<"\n";
//		}
//	}
	if(q<=0) return 0;
	while(q--)
	{
		if(flagg) cin>>t1>>t2;
		fr2=0;
		int ans=0;
		for(int i=0;i<t2.length();i++) fr2=(fr2*27+t2[i])%mod;
		for(int i=0;i<t1.length();i++)
		{
			if(!i) fr1[i]=t1[i];
			else fr1[i]=(fr1[i-1]*27+t1[i])%mod;
		}
		for(int i=0;i<t1.length();i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x=s1[j].length();
				int y;
				if(!i) y=0;
				else y=fr1[i-1];
				if((fr1[i+x-1]-y*fpow(27,i+1)%mod+mod)%mod
				==num1[j])
				{
					int xx=t1.length();
					if((fr1[xx-1]-num1[j]*fpow(27,i)+num2[j]*fpow(27,i)+mod)%mod
					==fr2)
					{
						ans++;
						continue;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
