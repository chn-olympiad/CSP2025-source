#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1],t;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			t=i;
			break;
		}
	}
	if(t%n==0){
		c=t/n;
		if(c%2==1){
			cout<<c<<' '<<n;
		}else{
			cout<<c<<' '<<1;
		}
	}else if(t/n==0){
		cout<<1<<' '<<t;
	}else if((t/n)%2==1){
		cout<<(t/n)+1<<' '<<n-(t%n)+1;
	}else if((t/n)%2==0){
		cout<<(t/n)+1<<' '<<t%n;
	}
	
	return 0;
}
