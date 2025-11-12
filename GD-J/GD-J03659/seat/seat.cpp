#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,m,x,y,s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
//	cout<<1;
	for(int i=0;i<n;i++)
	{
		
		for(int j=1;j<=m;j++)
		scanf("%lld",&a[i*m+j]);
	}
	
	x=a[1];
	y=n*m;
	
	sort(a+1,a+y+1,cmp);
	
	for(int i=0;i<=m;)
	{
		i++;
		for(int j=1;j<=n;j++)
		{
			s++;
			if(a[s]==x){
				cout<<i<<" "<<j;
				return 0;
			}
			
		}
		i++;
		for(int j=n;j>=1;j--)
		{
			s++;
			if(a[s]==x){
				cout<<i<<" "<<j;
				return 0;
			}
			
		}
	}
	return 0;
}
/*
4 5
14 15 16 17 18 19 20 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
