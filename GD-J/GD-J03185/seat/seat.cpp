#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0];
	sort(a,a+n*m,greater<int>());
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[s]==a1){
				cout<<i<<" "<<j;
			}
		s++;
		}
	}
	return 0;
}
