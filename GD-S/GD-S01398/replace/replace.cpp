#include<bits/stdc++.h>
using namespace std;
#define ll int
#define endl '\n'
const ll M=2e5+5;
ll n,q,f[M<<1],f2[M<<1],ans;
string s[M][2],t1,t2,s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			//cout<<"\n\n a new part\n";
			s1=s[i][0],s2=s[i][1];
			string st1=s1+'#'+t1,st2=s2+'#'+t2;
			ll k=0,sts=st1.size(),s1s=s1.size();
			//cout<<"sts:"<<sts<<"  s1s:"<<s1s<<endl;
			//cout<<st1<<" "<<st2<<endl;
			f[0]=f2[0]=0;
			//cout<<"0 ";
			for(int j=1;j<sts;j++)
			{
				k=f[j-1];
				while(k>0&&st1[j]!=st1[k]) k=f[k-1];
				if(st1[j]==st1[k]) k++;
				f[j]=k;
				//cout<<f[j]<<" ";
			}
			//cout<<endl;
			//cout<<"0 ";
			k=0;
			for(int j=1;j<sts;j++)
			{
				k=f2[j-1];
				while(k>0&&st2[j]!=st2[k]) k=f2[k-1];
				if(st2[j]==st2[k]) k++;
				f2[j]=k;
				//cout<<f2[j]<<" ";
			}
			//cout<<endl;
			for(int j=s1s<<1;j<sts;j++)
			{
				if(f[j]==s1s&&f2[j]==s1s)
				{
					bool tag=1;
					for(k=j+1;k<sts;k++)
					{
						if(st1[k]!=st2[k])
						{
							tag=0;
							break;
						}
					}
					for(k=s1s+1;k<j-s1s;k++)
					{
						if(st1[k]!=st2[k])
						{
							tag=0;
							break;
						}
					}
					if(tag)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
