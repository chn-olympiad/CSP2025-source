#include<bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,b=0;
	cin>>n>>m>>k;
	a[1]=k;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			b=i;
			break;
		}
	}
	b-=1;
	int c=b/n+1,r;
	if(c%2==1) {
		r=b%n+1;
	}else{
		r=m-b%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
