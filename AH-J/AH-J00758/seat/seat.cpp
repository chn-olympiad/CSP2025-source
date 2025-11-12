#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;
ll n,m,a[N*N],f[N][N],cnt,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>a[i];
	num=a[1];

	sort(a+1,a+1+cnt);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--) f[j][i]=a[cnt--];
		}else{
			for(int j=1;j<=n;j++) f[j][i]=a[cnt--];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==num){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
