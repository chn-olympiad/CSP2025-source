#include<bits/stdc++.h>
using namespace std;
int n,m;//nÐÐmÁÐ 
const int N=500;
struct kc{
	bool b=0;
	int a;
}a[N];
bool cmp(kc x,kc y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i].a;
	}
	a[1].b=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j].b) printf("%d %d",i,j);
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[i*n-j+1].b) printf("%d %d",i,j);
			}	
		}
	}
		
	return 0;
}
