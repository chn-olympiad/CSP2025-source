#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],t;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) t=i; 
	}
	if((t/n)%2==0){
		if(t%n==0) cout<<t/n<<' '<<n;
		else cout<<t/n+1<<' '<<t%n;
	}else{
		if(t%n==0) cout<<t/n<<' '<<n;
		else cout<<t/n+1<<' '<<n-t%n+1;
	}
	return 0;
}
