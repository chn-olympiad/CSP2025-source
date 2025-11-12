#include<iostream>
using namespace std;
int t,n,x1,x2,x3,sum,m=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--)
	{ 	
		sum = 0;
	 	cin >> n;
	 	int b[n];
		int a[n*3+1];
	 	for(int i=1;i<=n;i++)
	 	{
	 		cin >>a[i];
		}
		for(int i=1;i<=n;i=i+3)
		{
			
			int op=1;
			b[m] = max(a[i],a[i+1],a[i+2]);
			if(b[m]==a[i] and x1<=n/2 and op==1){
				op=0;
				x1++;
				sum = sum + a[i];
			}if(b[m]==a[i+1] and x2<=n/2 and op==1){
				op=0;
				x2++;
				sum = sum + a[i+1];
			}if(b[m]==a[i+3] and x3<=n/2 and op==1){
				op = 0;
				sum = sum + a[i+2];
				x3++;
			}else if(a[i+1] = max(a[i+1],a[i+2]) and x2<=n/2 and op==1){
				op=0;
				x2++;
				sum = sum + a[i+1];
			}else if(a[i+2] = max(a[i],a[i+2]) and x3<=n/2 and op==1){
				op=0;
				x3++;
				sum = sum + a[i+2];
			
			}else if(a[i] = max(a[i+1],a[i]) and x1<=n/2){
				sum =sum+a[i];
				x1++;
			}	
			else if( op==1){
			    op=0;
				x3++;
				sum = sum + a[i+2];
			}
			m++;
	 }
	 cout<<sum; 
} 
