#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,c;
	cin>>n>>m;
	int a[n*m];
	cin>>k;
	a[0]=k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==k){
			c=n*m-i;
			break;
		}
	}
	int x=(c-1)/n;
	if(x%2==0) cout<<(c-1)/n+1<<' '<<(c-1)%n+1;
	else cout<<(c-1)/n+1<<' '<<n-(c-1)%n;
	return 0;
}
