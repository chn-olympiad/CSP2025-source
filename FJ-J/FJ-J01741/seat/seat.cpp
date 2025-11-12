#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,s[105],su[15][15],x=1,y=1,d=1,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&s[i]);
	}
	int a=s[0];
	sort(s,s+n*m,cmp);
	for(int i=0;i<n*m;i++){
		su[x-1][y-1]=s[i];
		if(x==n&&y%2==1){
			d=0;
		}else if(x==n&&y%2==0){
			d=3;
		}else if(x==1&&y%2==1){
			d=1;
		}else if(x==1&&y%2==0){
			d=0;
		}
		x+=dx[d],y+=dy[d];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(su[i][j]==a){
				x=i+1,y=j+1;
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
}
