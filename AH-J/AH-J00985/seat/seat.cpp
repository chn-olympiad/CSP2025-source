#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[15][15],t[105];
LL n,m,k,sum;
bool cmp(LL x,LL y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++) cin>>t[i];
	sum=t[1];
	sort(t+1,t+n*m+1,cmp);
	for(LL j=1;j<=m;j++){
		if(j&1){
			for(LL i=1;i<=n;i++){
				a[i][j]=t[++k];
			}
		}
		else{
			for(LL i=n;i>=1;i--){
				a[i][j]=t[++k];
			}
		}
	}
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=m;j++){
			if(a[i][j]==sum){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
