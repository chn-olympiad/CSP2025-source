#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[110];
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
	LL r=a[1],w;
	sort(a+1,a+1+n*m,cmp);
	for(LL i=1;i<=m*n;i++){
		if(r==a[i]){
			w=i;
		}
	}
	LL l=1;
	while(1){
		if(w>n){
			l++;
			w-=n;
		}
		if(w<=n){
			if(l%2==1){
				cout<<l<<" "<<w;
			}else if(l%2==0){
				cout<<l<<" "<<m-w+1;
			}
			return 0;
		}
	}
	return 0;
}
