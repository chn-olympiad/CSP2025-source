#include<bits/stdc++.h>
#define int long long
using namespace  std;
const int N=1e7+7,M=1e3+7;
int n,m;
int a[N];
int b[M][M];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n+m+1,cmp);
//	for(int i=1;i<=k;i++){
//		if(a[i+1]>a[i]) swap(a[i+1],a[i]);
//	}

	if(r==a[1]){
		cout<<"1 1";
		return 0;
	}
	for(int i=1;i<=(n*m);i++){
		if(r==a[i]){
			if(i%n==0){
				if((i/n)&1){
					cout<<i/n<<" "<<n;
					exit(0);
				}else if((i/n)%2==0){
					cout<<i/n<<" "<<1;
					exit(0);
				}
			}
		}
	}
	for(int i=1,j=1;i<=n,j<=m;i++,j++){
			if(i<=n){
				b[i][j]=a[i];
			}
			if(j%2==0){
			i=n;
			while(i--){
					b[i][j]=a[i];
				}
			}
		}

	 for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r) {
				cout<<j<<" "<<i;
				exit(0);
			}
		}
	}
	exit(0);
}
