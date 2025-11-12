#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long  x=a[1],y;
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
		}
	}
	if(((y+n-1)/n)%2==1){
		cout<<(y+n-1)/n<<" ";
		if(y%n==0)cout<<n;
		else cout<<y%n;
	}
	else {
		cout<<y/n+1<<" "<<n-(y%n)+1;
	}
	return 0;
}
