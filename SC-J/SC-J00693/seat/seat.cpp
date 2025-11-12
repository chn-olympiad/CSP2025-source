#include<bits/stdc++.h>
using namespace std;
struct A{
	int x,z;
}a[105];
int n,m,t;
bool cmp(A x,A z){
	return x.x>z.x;
}
int ceil(int x){
	if(x%n==0){
		return x/n;
	}
	else{
		return x/n+1;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	t=n*m;
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i].x);
		a[i].z=i;
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++){
		if(a[i].z==1){
			int p=ceil(i);
			cout<<p<<' ';
			if(p%2==1){
				if(i%n==0){
					cout<<n;
				}
				else{
					cout<<i%n;
				}
				return 0;
			}
			else{
				if(i%n==0){
					cout<<1;
				}
				else{
					cout<<n-(i%n)+1;
				}
				return 0;
			}
		}
	}
	return 0;
}