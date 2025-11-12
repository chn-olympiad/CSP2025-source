#include <bits/stdc++.h>
using namespace std;

int a[625];
int vis[25][25];
int m,n,cnt=1;
int score;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1){
				vis[i][j]=a[cnt];
			}
			else{
				vis[i][m-j+1]=a[cnt];
			}
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(vis[j][i]==score){
				cout<<j<<' '<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
