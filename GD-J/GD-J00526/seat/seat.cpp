#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105],s[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i =1;i<=n*m;i++) scanf("%d",&s[i]);
	int ans=s[1];
	sort(s+1,s+n*m+1,greater<int>());
	int x=1,y=2,cnt=1;
	bool flag=0;
	a[1][1]=s[cnt];
	cnt++;
	while(x<=m&&y<=n){
		a[y][x]=s[cnt];
		cnt++;
		if(y==n||y==1){
			x++;
			flag=!flag;
			a[y][x]=s[cnt];
			cnt++;
			if(flag==0) y++;
			else y--;
		}
		else if(flag==0){
			y++;
		}else if(flag==1){
			y--;
		}else{
			continue;
		}
	}
	for(int i =1;i<=m;i++){
		for(int j =1;j<=n;j++){
			if(a[j][i]==ans){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
