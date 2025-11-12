#include <bits/stdc++.h>
using namespace std;
int i,j;
int a[110][110];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
	cin>>t;
	int n;
	cin>>n;
	int k,b,c; 
	cin>>k>>b>>c;
	int res=0;
	cin>>res;
	int MAX;
		 for(i=1;i<=n;i++)
		 { 
			 for(j=1;j<=3;j++)
			 {	
			  cin>>a[i][j];
			  while(n%2==0&&k<=n/2&&b<=n/2&&c<=n/2)
	        {
		      MAX=max(k,b);
		      MAX=max(k,c);
		      MAX=max(b,c);
		      res+=MAX;
			  if(1<=i<=n)
			 {
			 	b=c=0;
			   } 
	        }
			  }
			  cout<<res<<endl;
		 }
	return 0;
	}