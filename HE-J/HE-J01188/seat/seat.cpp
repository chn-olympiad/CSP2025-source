#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000];
long long num;
long long ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+m*n+1,cmp);
	long long xi=1,xj=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num){
			cout<<xj<<" "<<xi;
			return 0;
		}
		if(i%n==0)
		{
			xj++;
		}
		else if((i/n)%2==0){
			xi++;
		}
		else if((i/n)%2==1){
			xi--;
		}
	}
	
	return 0;
}
