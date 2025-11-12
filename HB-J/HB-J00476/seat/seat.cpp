#include <bits/stdc++.h>
using namespace std;
int a[110];
int k[25];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;cin>>n>>m;t=n;
	for(int i=1;i<=2*n;i++){
		if(i==2*n)k[0]=1;
		else{
			if(i/n==1&&i%n!=0){
				k[i]=t;t--;
			}
			else k[i]=i;
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			if(i%n==0)cout<<i/n<<' ';
			else cout<<(i+n)/n<<' ';
			cout<<k[i%(2*n)];break;
		}
	}
	return 0;
}
