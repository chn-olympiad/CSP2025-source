#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(LL &x,LL &y){
	return x>y;
}
LL n,m,a[110],x,y,c,r,b[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[(j-1)*n+i];
			if(b[i][j]==x){
				r=i;
				c=j;
			}
		}
	}
	if(c%2==0){
		cout<<c<<" "<<n-r+1;
	}else{
		cout<<c<<" "<<r;
	}
	return 0;
}
