#include<bits/stdc++.h>
using namespace std;
int m,n,nx;
bool cmp(int a,int b){
	return a>b;
}
void f(int x){
	int j=1;
	while(x>n){
		j++;
		x-=n;
	}
	if(j%2==0){
		cout<<j<<' '<<n+1-x;
	}else{
		cout<<j<<' '<<x;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	int c[l];
	for(int i=1;i<=l;i++){
		cin>>c[i];
	}
	nx=c[1];
	if(n==1&&m==1){
		cout<<1<<' '<<1;
		return 0;
	}
	sort(c+1,c+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(c[i]==nx){
			f(i);
			return 0;
		}
	}
	return 0;
}
