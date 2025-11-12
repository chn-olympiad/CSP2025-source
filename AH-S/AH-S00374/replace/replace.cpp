#include<bits/stdc++.h>
using namespace std;
int n,T,p[200010];
string s[200010][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(T--)
	{
		string x1,x2;
		cin>>x1>>x2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int a=x1.find(s[i][1]),b=x2.find(s[i][2]);
			if(a==b)
			{
				string t1=x1,t2=x2;
				int l=s[i][1].size();
				for(int j=a;j<a+l;j++)
				{
					t1[j]=' ';
					t2[j]=' ';
				}
				if(t1==t2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}	
    return 0;
}
