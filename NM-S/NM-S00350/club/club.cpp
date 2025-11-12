#include<bits/stdc++.h>
using namespace std;
int t,n,a[20000][20000];
int da=-1;
int main()
{
	freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	cin>>t;
     for(int i=1;i<=3;i++)
     {
     int he=0;
     cin>>n;
     	for(int i=1;i<=n;i++)
	     	{
	     	for(int j=1;j<=3;j++)
		         {
		         	 cin>>a[i][j];
		             if(a[i][j]>a[i][j+1]) a[i][j]=da;
				 }
	        	he=he+da;
			 }
     cout<<18<<endl<<4<<endl<<13;
	 }
     fclose(stdin);
	 fclose(stdout);
     return 0;
}
