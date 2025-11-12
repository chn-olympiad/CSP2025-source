#include<bits/stdc++.h>
using namespace std;
int a[105];
int cnt[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int tol=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++) cnt[i][j]=a[++tol];
		}
		else{
			for(int i=n;i>=1;i--) cnt[i][j]=a[++tol];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(cnt[i][j]==k){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
