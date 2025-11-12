#include<bits/stdc++.h>
using namespace std;
const int maxn=15;

int n,m,a[105],b[maxn][maxn],s,cnt=1;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+len,greater<int>());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				b[n-j+1][i]=a[cnt];
			}else{
				b[j][i]=a[cnt];
			}
			cnt++;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==s){
				cout<<j<<' '<<i;
			}
		}
	}
	
	return 0;
}