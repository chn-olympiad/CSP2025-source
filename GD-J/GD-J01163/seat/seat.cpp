#include<bits/stdc++.h>
using namespace std;
int n,m,l,p;
int a[10100];
inline bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[++l];
			if(i==1&&j==1)p=a[l];
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==p){
			int ii,jj;
			if(i%n)jj=i/n+1;
			else jj=i/n;
			if(jj%2==1){
				if(i%n)ii=i%n;
				else ii=n;
			}else{
				if(i%n)ii=n-i%n+1;
				else ii=1;
			}
			printf("%d %d",jj,ii);
			return 0;
		}
	}
	return 0;
}

