#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x;
	cin>>n>>m>>a[1];
	x=a[1];
	for(int i=2;i<=n*m;i++)scanf("%d",&a[i]);
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x==a[(i-1)*m+j]){
				if(i%2)cout<<i<<" "<<j;
				else cout<<i<<" "<<m-j+1;
			}
		}
	}
	return 0;
}
