#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int n,m,b,tot=0;
bool comp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);	
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) b=a[i];
	}
	sort(a,a+n*m,comp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0){
			for(int x=1;x<=n;x++){
				if(a[tot]==b){
					cout<<i<<" "<<x;
					return 0;
				}
				else tot++;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[tot]==b){
					cout<<i<<" "<<j;
					return 0;
				}
				else tot++;
			}
		}
		
	}
	return 0;
} 