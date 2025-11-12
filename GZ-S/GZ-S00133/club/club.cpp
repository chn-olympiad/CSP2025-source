#include<bits/stdc++.h>
using namespace std;
int s[100005][4],ma[6];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,r[4];
		cin>>n;
		for(int j=1;j<=n;j++)
		{
		int maxn=-1;
		for(int k=1;k<=3;k++)
		{
		cin>>s[j][k];
		 maxn=max(maxn,s[j][k]);
	}
	for(int k=1;k<=3;k++)
	if(maxn==s[j][k]){
	r[k]++;
	ma[i]+=maxn;
	}
	}
	int maxn1=-1,maxn2=-1;
	for(int m=1;m<=3;m++)
	{
	if(r[m]>n/2)
	{
	for(int e=1;e<=n;e++)
	maxn2=max(maxn2,s[e][m]);
	for(int w=1;w<=3;w++)
	{
	if(w!=m)
	for(int d=1;d<=n;d++)
	maxn1=max(maxn1,s[d][w]);
	r[m]--;
	r[w]++;
	}
	ma[i]=ma[i]+maxn1-maxn2;
}
}
}
    for(int i=1;i<=t;i++)
	cout<<ma[i]<<endl;
	return 0; 
}
