#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
struct AB{
	int k,b;
}a[106]; 
int n,m,wz=0;
bool cmp(AB x,AB y){
	return x.k>y.k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].k;
		a[i].b=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i].b==1){
			wz=i;
			break;
		}
	}
	int u = wz%(n*2);
	if(wz>(n*2)){
		if(u>n){
			int p=u-n;
			cout<<wz/n+1<<" "<<n-p+1;
		}else{
			cout<<wz/n+1<<" "<<u;
		}
		
	}else{
		if(u==1||u==0){
			cout<<wz/n+1<<" "<<1;
		}else if(u>n){
			int p = u-n;
			cout<<2<<" "<<n-p+1; 
		}else{
			cout<<1<<" "<<u;
		}
	}
	return 0;
} 
