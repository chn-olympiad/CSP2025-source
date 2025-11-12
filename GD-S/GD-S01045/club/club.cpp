#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][6],h;
void f(long long i,long long j,int x,int y,int z,long long k)
{
	if(x>(n/2)|| y >(n/2)||z>(n/2))return;
	if(i==n)h=max(h,k);
	f(i+1,1,x+1,y,z,k+a[i+1][1]);
	f(i+1,2,x,y+1,z,k+a[i+1][2]);
	f(i+1,3,x,y,z+1,k+a[i+1][3]);
	
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--)
	{
		h=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			cin>>a[i][j];	
		}
		
		f(1,1,1,0,0,a[1][1]);
		f(1,2,0,1,0,a[1][2]);
		f(1,3,0,0,1,a[1][3]);
		cout<<h<<'\n'; 
	}
	
	return 0;
}
