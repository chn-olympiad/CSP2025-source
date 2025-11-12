#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
int ma[15][15];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int score=a[1];
	int s=n*m;
	for(int i=2;i<=s;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ma[i][j]=a[++cnt];
			}
		}else{
			for(int j=m;j>=1;j--){
				ma[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ma[i][j]==score){
				cout<<i<<' '<<j<<'\n';
				break;
			}
		}
	}
	return 0;
}
