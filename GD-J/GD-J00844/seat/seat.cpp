#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[110];
int b[20][20];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=1;
	for (int i=1;i<=n;i++){
		if (i%2==1){
			for (int j=1;j<=m;j++){
				b[i][j]=a[cnt];
				cnt++;
			}
		}else{
			for (int j=1;j<=m;j++){
				b[i][j]=a[cnt];
				cnt++;
			}
			int t[20];
			for (int j=m;j>=1;j--){
				t[m-j+1]=b[i][j];
			}
			for (int j=1;j<=m;j++){
				b[i][j]=t[j];
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]==r){
				cout << i << ' ' << j;
				return;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
