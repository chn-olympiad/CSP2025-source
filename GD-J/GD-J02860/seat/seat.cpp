#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[121];
int xa;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xa=a[1];
	sort(a+1,a+n*m+1);
	
	int ai=0;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==xa)
		{
			ai=n*m+1-i;
			break;
		}
	}
	
	int l=0;
	
	while(l*m<ai) l++;
	
	cout<<l<<' ';
	if(l%2==1) cout<<ai-(l-1)*m;
	else cout<<m-(ai-(l-1)*m)+1;
	
	return 0;
}
