#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
const int mlen=5e5+5;
int n,q;
vector<vector<char>> x,y;
char b[mlen],c[mlen];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		vector<char> g,h;
		char e[maxn],f[maxn];
		cin>>e>>f;
		for (int i=0;i<strlen(e);i++)g.push_back(e[i]),h.push_back(f[i]);
		x.push_back(g),y.push_back(h);
	}
	while (q--)
	{
		int ans=0;
		cin>>b>>c;
		if (strlen(b)!=strlen(c))
		{
			cout<<0<<"\n";
			continue;
		}
		int i=0,j=strlen(b)-1;
		for (i;i<strlen(b)&&b[i]==c[i];i++);
		for (j;j>=0&&b[j]==c[j];j--);
		int min_len=j-i+1;
		
		for (int l=1;l<=n;l++)
		{
			if (x[l].size()<min_len)continue;
            int e=-10001,f=-10001;
            for (int g=j+1-x[l].size();g<=i;g++)
            {
            	bool flag=true;
            	for (int h=0;h<x[l].size();h++)
            	{
            		if (b[g+h]!=x[l][h])
            		{
            			flag=false;
            			break;
					}
				}
				if (flag)
				{
					e=g;
					break;
				}
			}
            for (int g=j+1-x[l].size();g<=i;g++)
            {
            	bool flag=true;
            	for (int h=0;h<x[l].size();h++)
            	{
            		if (c[g+h]!=y[l][h])
            		{
            			flag=false;
            			break;
					}
				}
				if (flag)
				{
					f=g;
					break;
				}
			}
			if (f==e&&e!=-10001&&f!=-10001)ans++;
		}
        cout<<ans<<"\n";
	} 
}
