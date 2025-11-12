#include <bits/stdc++.h>
using namespace std;
	int n=0,m=0,big,sum,c,l;
   int a[1000];
   int s[1000][1000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	
	}
	sum=a[0];
    for(int i=0;i<n*m;i++){
	for(int j=n*m-1;j>i;j--)
		{
			if(a[j]>a[i])
			{
				big=a[i];
				a[i]=a[j];
				a[j]=big;
			}
		}
		
	}

	cout<<endl;
	int h=0;
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   	     if(a[h]=sum)
   	     {
   	     	if(i%2==0)cout<<i+1<<" "<<j+1;
   	     	else cout<<i+1<<" "<<n-j;
			}
		     h++;
	   }
	 
   }
    
	return 0;
}
