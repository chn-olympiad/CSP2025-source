#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,l,a[105],b[105][105];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)for(int j=1;j<=n;j++)b[j][i]=a[++l];
		else for(int j=n;j>0;j--)b[j][i]=a[++l];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(b[i][j]==x)return cout<<j<<" "<<i,0;
	return 0;
}
