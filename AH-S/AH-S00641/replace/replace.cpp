#include <bits/stdc++.h>
using namespace std;
int n,q,sum[600000],l1;
struct T
{
	string a;
	string b;
	string c;
	string d;
}s[600000];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].b;
	for(int i=1;i<=q;i++)
	{
		string x,y;
	    cin>>s[i].c>>s[i].d;
	    l1=s[i].c.size();
	    for(int j=0;j<l1;j++)
	    {
			if(s[i].c[j]!=s[i].d[j])
			{
				x+=s[i].c[j];
				y+=s[i].d[j];
			}
		}
		for(int t=1;t<=n;t++)
		{
			if(s[t].a==x&&s[t].b==y)
			    sum[i]++;
			else if(s[t].a==s[i].c&&s[t].b==s[i].d)
			    sum[i]++;
	    }
	    cout<<sum[i]<<endl;
	}
    return 0;
}
