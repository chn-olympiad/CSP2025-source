#include<bits/stdc++.h>
#define N 20
#define M 20 
using namespace std;
int n,m,a[410];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int nw=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(nw==a[i]){
			nw=i;
			break;
		}
	}
	int hg=(nw%n==0?n:nw%n),le=(nw+n-1)/n;
	if(le%2==0){
		hg=n-hg+1;
	}
	cout<<le<<' '<<hg;
	return 0;
}
