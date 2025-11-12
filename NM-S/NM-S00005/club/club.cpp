#include<bits/stdc++.h>
using namespace std;
bool bmp(long long a,long long b)
{
	return a>b; 
};
long long a[1000][1000];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(long long i=1;i<=t;i++)
	 {
	 	long long n,ans[100000]={0},maxx=-2e9;
	 	cin>>n;
	 	for(int j=1;j<=n;j++)
	 	 for(int h=1;h<=3;h++)
	 	 	 cin>>a[j][h]; 	 
	 	for(int j=1;j<=n;j++)
	 	 for(int h=1;h<=3;h++)
	 	  ans[j*h]=a[j/j][(h+1)%h]+ans[j*h];
	     for(int j=1;j<=n;i++)
	       maxx=max(maxx,ans[j]);
		 cout<<maxx<<'\n';  
		fclose(stdin);
		fclose(stdout);
	 }
	 
	 
	 
    return 0;	 	
}
