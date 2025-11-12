#include <bits/stdc++.h>
using namespace std;                 
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int i=0;i<t;i++){
	int max=0;
   int a1[100000],a2[100000],a3[100000];
     int n;
     cin>>n;
     
   for(int j=0;j<n;j++)
   {cin>>a1[j];
    cin>>a2[j];
    cin>>a3[j];
    }
    
    for(int a=0;a<n;a++)
     {
		for(int b=0;b<n;b++)
		{
			for(int c=0;c<n;c++)
			{   
				
				if(a!=b && b!=c && c!=a)
				{
				if(a1[a]+a2[b]+a3[c]>=max)
				{
					max=a1[a]+a2[b]+a3[c];
				}	
				}
			}
		 }
	 }
	 cout<<max<<endl;
                    }
                    
return 0;
           }
