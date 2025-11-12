#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50;
int n,m,s[N*N],ans=0,a[N][N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int r=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==r){
			ans=i;
			break;
		}
	}
	//cout<<ans<<endl;
	int num=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2!=0)a[i][j]=num;
			else if(j%2==0)a[n-i+1][j]=num;
			num++;
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j];
		}cout<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
