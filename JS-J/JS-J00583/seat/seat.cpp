#include<bits/stdc++.h>
using namespace std;
int n,m,tot,scr[100002],Rscr,pre;
bool b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=n*m;
	scanf("%d",&scr[1]);
	Rscr=scr[1];
	for(int i=2;i<=tot;++i){
		scanf("%d",&scr[i]);
	}
	sort(scr+1,scr+tot+1,cmp);
	for(int i=1;i<=m;++i){
		if(i%2){
			for(int j=1;j<=n;++j){
				if(scr[++pre]==Rscr){
					printf("%d %d",i,j);
					b=1;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;--j){
				if(scr[++pre]==Rscr){
					printf("%d %d",i,j);
					b=1;
					break;
				}
			}
		}
		if(b)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}