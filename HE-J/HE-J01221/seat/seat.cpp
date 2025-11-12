#include <bits/stdc++.h>
using namespace std;
int n,m,k,q;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			if(a[++k]==q){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		for(int j=n;j>=1;j--){
			if(a[++k]==q){
				cout<<i+1<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

