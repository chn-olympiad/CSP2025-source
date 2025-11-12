#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n,m;
LL a[105];
LL x;
LL ans[15][15];
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(LL i=1;i<=n*m;i++) cout<<a[i]<<" ";
	//cout<<"\n";
	LL r=1,c=1;
	LL indx=1;
	char dir='L';
	while(indx<=n*m){
		ans[r][c]=a[indx];
		//cout<<r<<" "<<c<<" ";
		//cout<<ans[r][c]<<"\n";
		if(dir=='L'){
			if(r==n){c++;dir='U';}
			else r++;
		}else{
			if(r==1){c++;dir='L';}
			else r--;
		}
		indx++;
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(ans[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
