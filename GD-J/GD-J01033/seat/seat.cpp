#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(l==a[i]){
			l=n*m-i+1;
			break;
		}
	}
	int x=(l-1)/n+1,y;
	y=l-(x-1)*n;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
} 
