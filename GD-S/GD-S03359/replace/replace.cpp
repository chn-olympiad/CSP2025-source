#include<bits/stdc++.h>

using namespace std;

struct rpl
{
	int la,ra;
	int lb,rb;
};
rpl r[200005];
int la,ra,lb,rb;
int n,q;
string t;
long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=0;j<t.size();j++)
		{
			if(t[j]=='b')
			{
				r[i].la=j;
				r[i].ra=(t.size()-j-1);
				break;
			}
		}
		cin>>t;
		for(int j=0;j<t.size();j++)
		{
			if(t[j]=='b')
			{
				r[i].lb=j;
				r[i].rb=(t.size()-j-1);
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t;
		for(int j=0;j<t.size();j++)
		{
			if(t[j]=='b')
			{
				la=j;
				ra=(t.size()-j-1);
				break;
			}
		}
		cin>>t;
		for(int j=0;j<t.size();j++)
		{
			if(t[j]=='b')
			{
				lb=j;
				rb=(t.size()-j-1);
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
//			cout<<"original:"<<la<<" "<<ra<<'\n';
//			cout<<"target:"<<lb<<" "<<rb<<'\n';
//			cout<<"replace_original:"<<r[j].la<<" "<<r[j].ra<<'\n';
//			cout<<"replace_target:"<<r[j].lb<<" "<<r[j].rb<<'\n';
			if(r[j].la<=la&&r[j].ra<=ra)
			{
				if((la-r[j].la+r[j].lb)==lb&&(ra-r[j].ra+r[j].rb)==rb)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
