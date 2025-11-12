#include <bits/stdc++.h>
using namespace std;
int m,n,a[115],k;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int tmp=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			k=i;
			break;
		}
	}
	int c=k/n,r=k%n;
	if(r==0){
		if(c%2==0){
			cout<<c<<" "<<1;
		}
		else{
			cout<<c<<" "<<n;
		}
	}
	else{
		if((c+1)%2==0){
			cout<<c+1<<" "<<n-r+1;
		}
		else{
			cout<<c+1<<" "<<r;
		}
	}
	return 0;
}
