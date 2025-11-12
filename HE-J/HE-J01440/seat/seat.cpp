#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,b[110][110];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int len=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				b[i][j]=a[++len];
				if(b[i][j]==x){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[++len];
				if(b[i][j]==x){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
