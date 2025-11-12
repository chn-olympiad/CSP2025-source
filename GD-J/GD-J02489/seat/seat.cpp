#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R=0,ind=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[(i-1)*n+j]==R)
				{
//					cout<<a[(i-1)*n+j]<<" "; 
					cout<<i<<" "<<j;
				}
					
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{

				if(a[(i-1)*n+(n-j+1)]==R)
				{
//					cout<<a[(i-1)*n+(n-j+1)]<<" ";
					cout<<i<<" "<<j;
				}
					
			}
		}
 }
	
		
	return 0;
}
/*
4 5
88 100 99 98 97 96 95 94 93 92 91 90 89 87 86 85 84 83 82 81
*/
