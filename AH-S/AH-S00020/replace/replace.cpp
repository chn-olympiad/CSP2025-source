#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
char a[2][5000005];
struct Node{
	char ggbr,pf;
	int z,y;
}x[200005][2],xx[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf ("%d%d",&n,&q);
	for (int i=0;i<n;i++){
		scanf ("%s%s",a[0],a[1]);
		int l1=strlen(a[0]),l2=strlen(a[1]);
		x[cnt][0].ggbr='@';x[cnt][1].ggbr='@';
		for(int j=1;a[0][j+1];j++)
			if(a[0][j]!=a[0][j-1]&&a[0][j]!=a[0][j+1]){
				x[cnt][0].ggbr=a[0][j];x[cnt][0].z=j;x[cnt][0].y=l1-j-1;x[cnt][0].pf=a[0][j-1];
			}
		if(x[cnt][0].ggbr=='@'){
			if(a[0][0]!=a[0][1]){
				x[cnt][0].ggbr=a[0][0];x[cnt][0].z=0;x[cnt][0].y=l1-1;x[cnt][0].pf=a[0][1];
			}
			else{
				x[cnt][0].ggbr=a[0][l1-1];x[cnt][0].z=l1-1;x[cnt][0].y=0;x[cnt][0].pf=a[0][l1-2];
			}
		}
		for(int j=1;a[1][j+1];j++){
			if(a[1][j]!=a[1][j-1]&&a[1][j]!=a[1][j+1]){
				x[cnt][1].ggbr=a[1][j];x[cnt][1].z=j;x[cnt][1].y=l2-j-1;x[cnt][1].pf=a[1][j-1];
			}
		}
		if(x[cnt][1].ggbr=='@'){
			if(a[1][0]!=a[1][1]){
				x[cnt][1].ggbr=a[1][0];x[cnt][1].z=0;x[cnt][1].y=l2-1;x[cnt][1].pf=a[1][1];
			}
			else{
				x[cnt][1].ggbr=a[1][l2-1];x[cnt][1].z=l2-1;x[cnt][1].y=0;x[cnt][1].pf=a[1][l2-2];
			}
		}int flag=1;
		for(int j=cnt-1;j>=0;j--)
			if(x[j][0].ggbr==x[cnt][0].ggbr&&x[j][0].pf==x[cnt][0].pf&&x[j][0].z==x[cnt][0].z&&x[j][0].y==x[cnt][0].y&&x[j][1].ggbr==x[cnt][1].ggbr&&x[j][1].pf==x[cnt][1].pf&&x[j][1].z==x[cnt][1].z&&x[j][1].y==x[cnt][1].y){
				flag=0;break;
			}
		cnt+=flag;
	}
	for(int i=0;i<q;i++){
		scanf ("%s%s",a[0],a[1]);int l1=strlen(a[0]),l2=strlen(a[1]),sum=0;
		xx[i][0].ggbr='@';xx[i][1].ggbr='@';
		for(int j=1;a[0][j+1];j++){
			if(a[0][j]!=a[0][j-1]&&a[0][j]!=a[0][j+1]){
				xx[i][0].ggbr=a[0][j];xx[i][0].z=j;xx[i][0].y=l1-j-1;xx[i][0].pf=a[0][j-1];
			}
		}
		if(xx[i][0].ggbr=='@'){
			if(a[0][0]!=a[0][1]){
				xx[i][0].ggbr=a[0][0];xx[i][0].z=0;xx[i][0].y=l1-1;xx[i][0].pf=a[0][1];
			}
			else{
				xx[i][0].ggbr=a[0][l1-1];xx[i][0].z=l1-1;xx[i][0].y=0;xx[i][1].pf=a[0][l1-2];
			}
		}
		for(int j=1;a[1][j+1];j++){
			if(a[1][j]!=a[1][j-1]&&a[1][j]!=a[1][j+1]){
				xx[i][1].ggbr=a[1][j];xx[i][1].z=j;xx[i][1].y=l2-j-1;xx[i][1].pf=a[1][j-1];
			}
		}
		if(xx[i][1].ggbr=='@'){
			if(a[1][0]!=a[1][1]){
				xx[i][1].ggbr=a[1][0];xx[i][1].z=0;xx[i][1].y=l2-1;xx[i][1].pf=a[1][1];
			}
			else{
				xx[i][1].ggbr=a[1][l2-1];xx[i][1].z=l2-1;xx[i][1].y=0;xx[i][1].pf=a[1][l2-2];
			}
		}
		for (int j=0;j<cnt;j++)
			if(xx[i][0].ggbr==x[j][0].ggbr&&xx[i][1].ggbr==x[j][1].ggbr&&xx[i][0].z==x[j][0].z&&xx[i][1].y==x[j][1].y&&x[j][0].pf==xx[i][0].pf&&x[j][1].pf==xx[i][1].pf||x[j][0].pf==x[j][1].pf&&xx[i][0].pf==x[j][1].pf&&(xx[i][0].z-(x[j][0].z-x[j][1].z)==xx[i][1].z)&&(xx[i][0].y-(x[j][0].y-x[j][1].y)==xx[i][1].y)&&x[j][0].z<=xx[i][0].z&&x[j][0].y<=xx[i][0].y)
				sum++;	
		printf ("%d\n",sum);
	}
	return 0;
}
