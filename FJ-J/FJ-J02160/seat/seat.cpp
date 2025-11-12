#include<bits/stdc++.h>
using namespace std;
int n,m,cj;
int a[105];
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
	cj=a[1];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(cj==a[i]){
			if(i%n==0){
				if(i/n%2==0)cout<<i/n<<" "<<1;
				else cout<<i/n<<" "<<m;
			}
			else if(i/n%2!=0)cout<<i/n+1<<" "<<n-(i%n)+1;
			else if(i/n%2==0)cout<<i/n+1<<" "<<i%n;
		}
	}
	return 0;
}
