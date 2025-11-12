#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	   int n;
	   cin>>n;
	   int a[99];
	   int sum=0;
	   for(int i=0;i<n;i++){
		   cin>>a[i];
		   sum=sum+a[i];
		   }
		   if(n<3){
			   cout<<0<<endl;
			   return 0;
			   }
			    if(a[0]+a[1]>a[2]||a[2]+a[1]>a[0]||a[0]+a[2]>a[1]){
					cout<<1<<endl;
					}
					/* **********************************************************************************************
					 * 
					 * 
					 * 
					 * 
					 *                                2025.11.1 11:29
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * 
					 * ****************************************************************************************************
					 */
					 
	}

