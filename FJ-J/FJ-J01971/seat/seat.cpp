#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[105][105],b[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int sum=b[1];
	sort(b+1,b+(n*m)+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=b[++cnt];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=b[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sum){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
