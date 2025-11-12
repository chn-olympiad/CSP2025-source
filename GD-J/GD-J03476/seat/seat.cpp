#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],k,cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)
		k=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int t=1;t<=m;t++)
	{
		if(t%2){
			for(int i=1;i<=n;i++){
				b[i][t]=a[++cnt];
				if(a[cnt]==k)
				{
					cout<<t<<" "<<i;
					return 0;
				}
			}
		}
		else for(int i=n;i>=1;i--){
			b[i][t]=a[++cnt];
				if(a[cnt]==k)
				{
					cout<<t<<" "<<i;
					return 0;
				}
		}
	}
	
	
	return 0;
}
