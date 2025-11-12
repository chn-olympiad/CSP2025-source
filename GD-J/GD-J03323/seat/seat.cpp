#include<bits/stdc++.h>
using namespace std;
int u[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,p=1,ans=0;
	cin>>x>>y;
	cin>>u[1];
	int as=u[1];
	for(int q=2;q<=x*y;q++)
	{
		cin>>u[q];
		if(u[q]>as)p++; 
	}
	for(int i=1;i<=x;i++)
	{
		if(i%2==1){
			for(int j=1;j<=y;j++) {
				ans++;
				if(ans==p){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=y;j>=1;j--) {
				ans++;
				if(ans==p){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
