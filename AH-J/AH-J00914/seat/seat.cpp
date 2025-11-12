#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[105],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,gc;
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++)
    {
		cin>>a[i];
		if(i==1) gc=a[i];
	}
    sort(a+1,a+l+1,cmp);
    for(int i=1;i<=m;i++)
    {
		if(i%2==0)
		{
			for(int j=n;j>0;j--)
			{
				b[i][j]=a[i*n+1-j];
			}
		}
		else{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[i*n-n+j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++)
	        if(b[i][j]==gc) cout<<i<<" "<<j;
    return 0;
}
