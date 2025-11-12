#include<bits/stdc++.h>
using namespace std;
int n,m,r;
struct A{
	int id,s;	
}a[10005];
bool cmp(A x,A y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].s;
	}
	r=a[1].id;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==r){
			cout<<i/n+(i%n);
			cout<<" ";
			if((i/n+(i%n))%2==1){
				if((i%n)){
					cout<<i%n;
				}
				else{
					cout<<n;
				}
			}else{
				if(i%n){
					cout<<n+1-(i%n);
				}
				else{
					cout<<1;
				}
			}
			break;	
		}
	}
	return 0;
} 
