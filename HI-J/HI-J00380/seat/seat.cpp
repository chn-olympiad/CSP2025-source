#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005], k[105][105];
bool comp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p=a[1];
	sort(a+1,a+1+n*m,comp);
	bool q=0;
	int j=1, y=1;
	while(j<=m){
		if(q==0){
			for(int i=1;i<=n;i++){
				k[i][j]=a[y];
				y++;
			}
			q=1;
		}
		else if(q==1){
			for(int i=n;i>=1;i--){
				k[i][j]=a[y];
				y++;
			}
			q=0;
		}
		j++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			if(k[i][j]==p){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

