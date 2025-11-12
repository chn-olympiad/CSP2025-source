#include<bits/stdc++.h>
using namespace std;
long long n,q,init[110000],obot[110000];
bool you[110000];
string a,b;
vector<string> Us[110000],As[110000];
inline bool check(long long f,long long st,long long num)
{
	for(int i=0;i<Us[num].size();i++)
	{
		bool po=true;
		for(int o=f;o<=st;o++)
		{
			if(a[o-1]!=Us[num][i][o-f]||b[o-1]!=As[num][i][o-f])
			{
				po=false;
				break;
			}
		}
		if(po)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string nini,bol;
		cin>>nini>>bol;
		you[nini.size()]=true;
		Us[nini.size()].push_back(nini);
		As[bol.size()].push_back(bol);
	}
	while(q--)
	{
		long long g=0;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=a.size();i++)
		{
			if(a[i-1]!=b[i-1])
			{
				init[i]=1;
			}
			init[i]+=init[i-1];
			if(a[a.size()-i+1]!=b[a.size()-i+1])
			{
				obot[a.size()-i+1]=1;
			}
			obot[a.size()-i+1]+=obot[a.size()-i+2];
		}
		for(int i=1;i<=a.size();i++)
		{
			for(int o=1;o<=i;o++)
			{
				if(init[i]==obot[o]&&you[i-o+1])
				{
					if(check(o,i,i-o+1))
					{
						g++;
					}
				}
			}
		}
		cout<<g<<endl;
	}
}
