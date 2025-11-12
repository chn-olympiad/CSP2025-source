#include <iostream>
using namespace std;
int nn[4],ans,T,n,in[10010][4];
int read(){
	char inc=getchar();
	int re=0;
	while(inc<'0'||inc>'9') inc=getchar();
	while(inc>='0'&&inc<='9'){
		re=(re<<3)+(re<<1)+(inc^'0');
		inc=getchar();
	}
	return re;
}
void print(int out){
	if(out>9) print(out/10);
	putchar(out%10+'0');
}
void dfs(int an,int ii){
	for(int i=1;i<=3;i++){
		if(nn[i]>0){
			nn[i]--;
			if(ii==n&&an+in[ii][i]>ans) ans=an+in[ii][i];
			dfs(an+in[ii][i],ii+1);
			nn[i]++;
		}
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			in[i][1]=read(),in[i][2]=read(),in[i][3]=read();
		}
		nn[1]=(n>>1),nn[2]=nn[1],nn[3]=nn[1];
		dfs(0,1);
		print(ans);
		putchar('\n');
	}
	return 0;
}
