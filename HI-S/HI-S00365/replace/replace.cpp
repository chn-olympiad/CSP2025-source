#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct yj{
	string a,b;
}a[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	while(t--)
	{
		string q,w;int num=0;
		int ans=0;
		cin>>q>>w;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<q.size();j++)
			{
				if(q[j]==a[i].a[0])
				{
					int ans=0,v=j;
					int x=j;
					while(q[v]==a[i].a[ans]&&v<q.size()&&ans<a[i].a.size()) ans++,v++; 
					if(ans==a[i].a.size())
					{
						ans=0;
						string p;
						p+=q;
						for(int k=x;k<x+a[i].a.size();k++)
						{
							p[k]=a[i].b[ans++];
						}
						if(p==w) num++;
					}
				}
				
			}
		}
	cout<<num<<endl;
	}
	return 0;
}

