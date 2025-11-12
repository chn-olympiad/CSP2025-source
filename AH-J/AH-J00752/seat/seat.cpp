#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a0=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a0==a[i]){
			k=i;
			break;
		}
	}
	if(k%n==0){
		int l=k/n;
		if(l%2==1) cout<<l<<" "<<n;
		else cout<<l<<" "<<"1";
	}else{
		int l=(k-k%n)/n+1;
		if(l%2==1) cout<<l<<" "<<k%n;
		else cout<<l<<" "<<n+1-k%n;
	}
	return 0;
} 
