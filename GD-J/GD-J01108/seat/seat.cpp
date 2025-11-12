#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,x=0,f=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)
			x=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1,j=1,it=1;i<=n+1,j<=m+1,it<=n*m;it++)
	{
		if(a[it]==x)
		{
			cout<<j<<" "<<i<<'\n';
			return 0;
		}
		if(f==1){
			j++;
			f=0;
			continue;
		}	
		if(i==n)
		{
			if(j%2==1){
				j++;
				continue;
			}
		}			
		if(j%2==1) i++;			
		else i--;	
		if(i==1){
			if(j%2==0){
				f=1;
				continue;
			}			
		}
	} 
	return 0;
}
/*
3 4
89 100 98 97 96 95 93 94 91 92 90 99
4 3
89 100 98 97 96 95 93 94 91 92 90 99
*/
