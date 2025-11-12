#include<bits/stdc++.h>
using namespace std;
struct soda{
	int so,da;
}a[105];
bool cmp(soda x,soda y){
	return x.so>y.so;
}
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].so;
		a[i].da=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int op=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[op].da==1){
				cout<<i<<" "<<j;
				return 0;
			}else{
				op++;
			}
		}i++;
		for(int j=n;j>=1;j--){
			if(a[op].da==1){
				cout<<i<<" "<<j;
				return 0;
			}else{
				op++;
			}
		}
	}
	return 0;
}