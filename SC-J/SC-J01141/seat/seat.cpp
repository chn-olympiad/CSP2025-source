#include<bits/stdc++.h>
using namespace std;
int n,m,sc,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[(i-1)*m+j]==sc){
				if(i%2) cout<<i<<' '<<j;
				else cout<<i<<' '<<m-j+1;
			}
		}
	}
	return 0;
}