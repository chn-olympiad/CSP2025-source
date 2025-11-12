#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int li;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	li=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[cnt];
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==li){
				cout<<i<<" "<<j;
				break;
			}
		}
	} 
	return 0;
}
