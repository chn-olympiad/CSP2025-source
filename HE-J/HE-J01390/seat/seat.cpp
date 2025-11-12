#include<bits/stdc++.h>
using namespace std;
int jx(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10001];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1,jx);
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			p=i;
			break;
		}
	}
	if(p%n==0)
		cout<<p/n<<' '<<n;
	else if((int(p/n)+1)%2==1)
		cout<<int(p/n)+1<<' '<<p%n;
	else cout<<int(p/n)+1<<' '<<n-p%n+1;
}
