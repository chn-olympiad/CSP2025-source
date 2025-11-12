#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+1+n*m);
	int num=n*m;
	for(int i=1;i<=m;i++){
		for(int j=(i&1?1:n);0<j&&j<=n;j+=(i&1?1:-1)){
			if(a[num--]==a[0]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
