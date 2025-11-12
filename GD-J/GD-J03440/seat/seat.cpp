#include<bits/stdc++.h>
using namespace std;
int n,m,mp[15][15],a[105],cnt,num,r,k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&k);
			a[++cnt]=k;
		}
	}
	r=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[i][j]=a[++num];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				mp[i][j]=a[++num];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==r){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
    return 0;
}
