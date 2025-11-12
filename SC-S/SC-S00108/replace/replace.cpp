#include<bits/stdc++.h>
using namespace std;
string s[200010][2];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		cin>>s1>>s2;
		int l=s1.length(),r=0,ans=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]!=s2[i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int ll=l;ll>=0;ll--)
		{
			for(int rr=r;rr<s1.length();rr++)
			{
				//cout<<ll<<" "<<rr<<" "<<s1.substr(ll,rr-ll+1)<<"\n";
				for(int i=1;i<=n;i++)
				{
					
					if(s1.substr(ll,rr-ll+1)==s[i][0])
					{
						string s3=s1;
						s1.replace(ll,rr-ll+1,s[i][1]);
						if(s1==s2)ans++;
						s1=s3;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}