#include<bits/stdc++.h>
using namespace std;
int a[101],b[11][11],k,l;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}	
	l=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i])
			{
				k=a[j];
				a[j]=a[i];
				a[i]=k;
			}
		}
	}
	int r=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{

			if(i%2==1)
			{
				b[j][i]=a[r];
				if(a[r]==l){
					cout<<i<<" "<<j;
					return 0;
				}
				r++;
			}
			if(i%2==0)
			{
				int z=0;
				b[m-z][i]=a[r];
				if(a[r]==l){
					cout<<i<<" "<<m-z;
					return 0;
				}
				r++,z++;
				
			}
		}
	}
}
