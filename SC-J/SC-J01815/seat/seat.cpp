#include<bits/stdc++.h>
using namespace std;
int a[10000];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<(i-1)/n+1<<' ';
			if(((i-1)/n+1)&1){
				cout<<(i%n==0?n:i%n);
			}
			else{
				cout<<n+1-(i%n==0?n:i%n);
			}
			return 0;
		}
	}
}