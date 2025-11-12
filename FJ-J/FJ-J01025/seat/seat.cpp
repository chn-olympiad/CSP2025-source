#include<bits/stdc++.h>
using namespace std;
int n,m,s[110],a[15][15],pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
		if(i==1)pos=s[1];
		s[i]*=-1;
	}
	sort(s+1,s+n*m+1);
	for(int i=1;i<=n*m;i++){
		s[i]*=-1;
	}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				a[j][i]=s[m*(i-1)+j];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[n-j+1][i]=s[m*(i-1)+j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==pos){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
