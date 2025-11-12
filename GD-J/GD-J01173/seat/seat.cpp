#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],now;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			now=i;
			break;
		}
	}
	cout<<ceil(now*1.0/n)<<" ";
	if(now%(2*n)>0&&now%(2*n)<=n) cout<<now%(2*n);
	else if(now%(2*n)==0) cout<<1;
	else cout<<2*n-now%(2*n)+1;
	return 0;
} 
