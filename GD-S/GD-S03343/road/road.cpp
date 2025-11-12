#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int n,k,m;
int m1[100005][4],m2[10005];
int k1[11][100005],k2[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>m1[i][j];
		}
	 } 
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>k1[i][j];
		}
	 } 	 
	int min1=k1[1][1],temp=0,num=1;
	for(int i=1;i<=m;i++)
	{
		m2[i]=m1[i][3];
	 } 
	 sort(m2+1,m2+1+m);
	 temp+=m2[1]+m2[2];
	 for(int i=2;i<=k;i++)
	 {
		if(min1>k1[i][1])
		{
			min1=min(k1[i][1],min1);
			num=i;
		}
	 }
	sort(k1[num]+1,k1[num]+1+n+1);
	 temp+=min1+k1[num][3]+k1[num][2];
	 cout<<temp;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
