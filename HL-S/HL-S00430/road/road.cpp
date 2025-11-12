#include<bits/stdc++.h>
using namespace std;
int u[1000000];
int v[1000000];
int w[1000000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	 for(int i=0;i<m;i++)
	 {
	 	cin>>u[i]>>v[i]>>w[i];
	 }
	 int b[k][n];
	 for(int j=0;j<k;j++)
	 {
	 	cin>>b[j][0];
	 	for(int i=1;i<=n;i++)
		 {
		 	
		 	cin>>b[j][i];
		 }
	 	
	 }
	 sort(w,w+m);
	 int sum=0;
	 if(k>=n)
	 {
	 	sum=0;
	 }
	 else
	 {
	 	for(int i=0;i<n-k;i++)
	 	{
	 		sum+=w[i];
		 }
	 }
	 cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0; 
 } 
