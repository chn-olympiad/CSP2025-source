#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int a[20][20];
int b[500];

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[++cnt];
		}
	}	
	int x=b[1];
	sort(b+1,b+cnt+1,cmp);
	int k=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=b[++k];
			}
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=b[++k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x==a[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

