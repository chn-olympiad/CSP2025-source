#include <bits/stdc++.h>
using namespace std;
int a[1000],g[101][101];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=0,num=1;
	for(int j=1;j<=m;j++){
		cnt++;
		if(cnt%2!=0){
			for(int i=1;i<=n;i++){
				g[i][j]=num;
				num++;
			}
		}else{
			for(int i=n;i>=1;i--){
				g[i][j]=num;
				num++;
			}
		}
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			id=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==id){
				cout<<j<<" "<<i;
				return;
			}
		}
	}
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	solve();
	return 0;
}
