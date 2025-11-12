#include<bits/stdc++.h>
using namespace std;
int n,q,imax=0;
string s1,s2,x[200005],y1[200005],y2[200005],z[200005];
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
    	cin>>s1>>s2;
    	bool pd=false;
    	for(int j=0;j<int(s1.size());j++)
    	{
    		if(s1[j]!=s2[j])
    		{
    			y1[i]+=z[i];
    			y1[i]+=s1[j];
    			y2[i]+=z[i];
    			y2[i]+=s2[j];
    			z[i]="";
			}
			else
			{
				if(pd)
				z[i]+=s1[j];
				else
				x[i]+=s1[j];
			}
		}
		imax=max(imax,int(y1[i].size()));
	}
	while(q--)
	{
		string q1,q2,yq1,yq2,xq,zq;
		cin>>q1>>q2;
    	bool pd=false;
    	for(int j=0;j<int(q1.size());j++)
    	{
    		if(q1[j]!=q2[j])
    		{
    			yq1+=zq;
    			yq1+=q1[j];
    			yq2+=zq;
    			yq2+=q2[j];
    			zq="";
			}
			else
			{
				if(pd)
				zq+=q1[j];
				else
				xq+=q1[j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(int(yq1.size())!=int(y1[i].size())||int(yq2.size())!=int(y2[i].size()))
			continue;
			bool pd=true;
			for(int j=0;j<int(y1[i].size());j++)
			if(yq1[j]!=y1[i][j])
			pd=false;
			for(int j=0;j<int(y2[i].size());j++)
			if(yq2[j]!=y2[i][j])
			pd=false;
			if(!pd)
			continue;
			if(int(xq.size())<int(x[i].size())||int(zq.size())<int(z[i].size()))
			continue;
			pd=true;
			for(int j=0;j<int(z[i].size());j++)
			if(z[i][j]!=zq[j])
			{
				pd=false;
				break;
			}
			for(int j=x[i].size()-1;j>=0;j--)
			if(x[i][j]!=xq[xq.size()-x[i].size()+j])
			{
				pd=false;
				break;
			}
			if(pd)
			ans++;
		}
		cout<<ans<<"\n";
	}
    return 0;
}
