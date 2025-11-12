#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node s[5000006];
bool cmp(node x,node y)
{
     return x.a>y.a;	
}
int main()
{   freopen("r","club.in",stdin);
    freopen("w","club.out",stdout);
    int t;
    cin>>t;
    int sum[t+6]={0};
    for(int j=1;j<=t;j++)
    {
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s+1,s+1+n,cmp);
		
		for(int i=1;i<=n/2;i++)
		{
			sum[j]+=s[i].a;
		}
		
	}
    for(int i=1;i<=t;i++)
    {
		cout<<sum[i]<<endl;
	}
    return 0;
}
