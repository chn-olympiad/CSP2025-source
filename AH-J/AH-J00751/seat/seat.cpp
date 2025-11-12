#include<bits/stdc++.h>
using namespace std;
int m,n,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],x;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		x=i*n-n;
		for(int j=1;j<=n;j++){
			if(a[x+j]==t){
				if(i%2==1)cout<<i<<" "<<j;
				else cout<<i<<" "<<n-j+1;
			}
		}
	}
	return 0;
}
