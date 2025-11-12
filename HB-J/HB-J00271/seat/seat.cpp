#include<bits/stdc++.h>
using namespace std;
int n,m,se[15][15],mark[105],cnt=1,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&mark[i]);
	}
	k=mark[1];
	sort(mark+1,mark+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			se[j][i]=mark[cnt];
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(se[i][j]==k){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

