#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l[200005];
string x,y,a[200005],b[200005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		l[i]=a[i].size();
		a[i]=" "+a[i];
		b[i]=" "+b[i];
	}
	while(m--)
	{
		int s=0;
		cin>>x>>y;
		int nn=x.size(),mm=y.size();
		x=" "+x,y=" "+y;
		if(nn!=mm)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1; i<=nn; i++)
		{
			int ok=1;
			for(int k=1; k<i; k++)
				if(x[k]!=y[k])
				{
					ok=0;
					break;
				}
			if(!ok) break;
			for(int j=i; j<=nn; j++)
			{
				ok=1;
				for(int k=j+1; k<=nn; k++)
					if(x[k]!=y[k])
					{
						ok=0;
						break;
					}
				if(!ok) continue;
				for(int k=1; k<=n; k++)
				{
					int ff=1;
					if(j-i+1!=l[k]) continue;
					for(int id1=i,id2=1; id1<=j || id2<=l[k]; id1++,id2++)
						if(x[id1]!=a[k][id2] || y[id1]!=b[k][id2])
						{
							ff=0;
							break;
						}
					s+=ff;
				}
			}
		}
		cout<<s<<"\n";
	}
    return 0;
}
