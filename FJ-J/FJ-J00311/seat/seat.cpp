#include<bits/stdc++.h>
using namespace std;
int n,m,a[300001],b[101][101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[++cnt];
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
	}
	int hzb,zzb;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==cj) {
				hzb=i;
				zzb=j;
				break;
			}
		}
	}
	cout<<zzb<<' '<<hzb;
	return 0;
}
