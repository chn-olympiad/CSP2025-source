#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
struct node
{
	string u,v;
	int len;
};
bool cmp(node x,node y) { return x.len<y.len; }
vector <node> e[N];
int n,q,sum[2005][2005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string u,v;
		cin>>u>>v;
		int len=u.length();
		if(len==1)
		{
			sum[u[0]-'a'+1][v[0]-'a'+1]++;
		}
		else if(len==2)
		{
			sum[(u[0]-'a'+1)+(u[1]-'a'+1)*27][(v[0]-'a'+1)+(v[1]-'a'+1)*27*27]++;
		}
		else
		{
			node T;
			T.len=len;
			T.u=u;
			T.v=v;
			int t=(u[0]-'a'+1)+(v[1]-'a'+1)*27+(u[2]-'a'+1)*27*27;
			e[t].push_back(T);
		}
	}
	for(int i=0;i<=1000000;i++) sort(e[i].begin(),e[i].end(),cmp);
	while(q--)
	{
		string a,b;
		ll ans=0;
		cin>>a>>b;
		int len=a.length();
		int g=-1;
		int r=-1;
		for(int i=0;i<len;i++)
		{
			if(a[i]!=b[i]) r=i;
			if(a[i]!=b[i]&&g==-1) g=i;
		}
		for(int i=0;i<len;i++)
		{
			if(g>-1&&i>g) break;
			if((i==r&&g==r)||r==-1) ans+=sum[a[i]-'a'+1][b[i]-'a'+1];
			if(i<len-1&&i+1>=r&&r-g<=1) ans+=sum[a[i]-'a'+1+(a[i+1]-'a'+1)*27][b[i]-'a'+1+(b[i+1]-'a'+1)*27];
			if(i>=len-2) continue;
			int x=a[i]-'a'+1+(b[i+1]-'a'+1)*27+(a[i+2]-'a'+1)*27*27;
			int p=e[x].size();
			int l=-1,cnt=1;
			while(cnt)
			{
				int k=l+cnt;
				if(k>=p||e[x][k].len>r-i) cnt/=2;
				else cnt*=2,l=k;
			}
			for(int j=l+1;j<p;j++)
			{
				int len=e[x][j].len;
				ans++;
				for(int k=0;k<len;k++)
				{
					if(a[i+k]!=e[x][j].u[k]||b[i+k]!=e[x][j].v[k])
					{
						ans--;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
