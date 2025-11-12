#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0;
int st[12][12];
int scr[144];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++)
		scanf("%d",&scr[i]);
	int anscr=scr[1];
	sort(scr+1,scr+1+(n*m),cmp);
	for(int i=1;i<=(n*m);i++)
		if(anscr==scr[i]) ans=i;
		
	int num=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			st[j][i]=num,num++;
		i++;
		for(int j=n;j>=1;j--)
			st[j][i]=num,num++;
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(st[i][j]==ans) ans1=i,ans2=j;
		}
	}
	printf("%d %d\n",ans2,ans1);
	return 0;
}
