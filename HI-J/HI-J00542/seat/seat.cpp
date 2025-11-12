#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b,c;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if((c/n)%2==1){
		if(c%n==0){
			cout<<c/n<<" "<<n;
		}else{
			cout<<c/n+1<<" "<<n-(c-n)+1;
		}
	}else{
		if(c%n==0){
			cout<<c/n<<" "<<1;
		}else{
			cout<<c/n+1<<" "<<c%n;
		}
	}
	return 0;
}
