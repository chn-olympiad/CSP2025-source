#include<bits/stdc++.h> 
using namespace std;
struct S{
	string a,b;
}a[200005];
bool cmp(S x,S y)
{
	return x.a<y.a;
}
int n,q;
string f1,f2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		cin>>f1>>f2;
		int dp[5000005];
		memset(dp,0,sizeof(dp));
		int i;
		for(i=0;i<f1.length();i++)
		{
			if(i>0)
				dp[i]=dp[i-1];
			if(f1[i]!=f2[i])
			{
				int m=1;
				while(a[m].a[0]!=f1[i]&&m<=n){
					m++;
				}
				if(m>n)
				{
					cout<<0<<endl;
					continue;
				}
				while(a[m].a[0]==f1[i]&&m<=n){
					if(a[m].a==substr(f1,i,i+a[m].a.length()-1)&&a[m].b==substr(f2,i,i+a[m].a.length()-1))
					{
						dp[i+a[m].a.length()-1]=dp[];
					}
					m++;
				}
			}
		}
	}
}
