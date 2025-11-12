#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[111];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m);
	for(int p=1;p<=n*m;p++){
		if(a[p]==s){
			int i=n*m+1-p;
			cout<<(i-1)/n+1<<' ';
			if((i/n+1)%2==1) cout<<i%n;
			else cout<<n-i%n;
			cout<<endl;
			return 0;
		}
	}
}
