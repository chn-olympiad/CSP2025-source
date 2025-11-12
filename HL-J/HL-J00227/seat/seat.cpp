#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+k);
	for(int i=1;i<=k;i++){
		if(c==a[i]){
			c=k-i+1;
			break;
		}
	}
	if(((c-1)/n)%2==0){
		cout<<(c-1)/n+1<<" "<<c%n+(c%n==0)*n;
	}else cout<<(c-1)/n+1<<" "<<n+1-c%n-(c%n==0)*n;
	return 0;
}