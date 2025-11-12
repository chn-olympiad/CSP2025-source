#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],b[100][100],id,w=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j];
			if(i==1&&j==1) id=a[1];
		}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[w];
				w++;
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[w];
				w++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==id){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
