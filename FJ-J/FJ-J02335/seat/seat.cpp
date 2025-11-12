#include<bits/stdc++.h>
using namespace std;
int scR,sca[110],n,m,squ[15][15];
//scR->littleR's score		sca->all students' score	squ->square of all students
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//别注释freopen！
	//多测要清空！
	//做完检查！
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&scR);
	sca[1]=scR;
	for(int i=2;i<=(n*m);i++){
		scanf("%d",&sca[i]);
	}
	sort(sca+1,sca+n*m+1,cmp);
	int cnt=0;//actually it just does few effects 
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				squ[i][j]=sca[++cnt];
			}
		}else if(i%2==0){//truth:i can delete if(i%2==0),but i doesn't do so :)
			for(int j=m;j>=1;j--){
				squ[i][j]=sca[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(squ[i][j]==scR){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
//done on 9:19
