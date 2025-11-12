#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q;
int a[N];
string s[N][2];
struct node
{
	string st;
	int num;
};
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		queue<node> q;
		q.push({t2,0});
		map<string,bool> vis;
		while(!q.empty())
		{
			node x=q.front();
			q.pop();
			vis[x.st]=1;
			if(x.st==t1)
			{
				cout<<x.num<<"\n";
				break;
			}
			for(int i=1;i<=n;i++)
			{
				int len=s[i][1].size();
				for(int j=0;j<x.st.size()-len+1;j++)
				{
					string ST=x.st.substr(0,j)+t1+x.st.substr(j+len-1,x.st.size()-(j+len));
					if(x.st.substr(j,len)==t2&&vis[ST]==0)
					{
						q.push({x.st.substr(0,j)+t1+x.st.substr(j+len-1,x.st.size()-(j+len-1)),x.num+1});
						if(ST==t1)
						{
							cout<<x.num+1<<"\n";
							break;
						}		
//						cout<<x.st.substr(0,j)+t1+x.st.substr(j+len-1,x.st.size()-(j+len))<<"\n";
//						return 0;
					}
				}
			}
		}
	}
    return 0;
}

