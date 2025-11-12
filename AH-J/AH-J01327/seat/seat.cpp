#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,r;
int a[110],b[20][20];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int cnt=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			b[i][j]=a[cnt++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==r){
				if(j%2==0) i=n-i+1;
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}

