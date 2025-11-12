#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int n,m;
int maxn=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n*m;i++){
		if(a[1]==maxn){
			cout<<1<<" "<<1;
		}
	}
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}