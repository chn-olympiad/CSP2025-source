#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=150;
int n,m,a[N],k,tot=1,s[N][N];
bool vis[N][N];
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
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s[j][i]=a[tot++];
			}
		}else{
			for(int j=n;j>=1;j--){
				s[j][i]=a[tot++];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92


*/
