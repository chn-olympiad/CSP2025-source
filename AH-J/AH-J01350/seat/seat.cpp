#include<bits/stdc++.h>
using namespace std;
int a[100000],bj;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;//hang lie
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r;
	r=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			bj=i;
		}
	}
	if(bj<=n){
		cout<<1<<" "<<bj;
	}
	else{
		cout<<ceil(bj/n)<<" "<<bj%n+1;
	}
	return 0;
}
