#include <iostream>
using namespace std;
int n,m,px[10010],ans,in2[10010];
char in1[10010];
bool inb[10010];
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
void judge(){
	int nn=0,q=0;
	for(int i=1;i<=n;i++){
		if(nn>=m){
			ans++;
			return;
		}
		if(in1[i]=='0') q++;
		else if(px[i]>q) nn++;
		else q++;
	}
	if(nn>=m) ans++;
}
int dfs(int a){
	for(int i=1;i<=n&&a<=n;i++){
		if(!inb[i]){
			px[a]=in2[i],inb[i]=true;
			if(a==n){
				judge();
			}
			dfs(a+1);
			inb[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		in1[i]=getchar();
	}
	for(int i=1;i<=n;i++){
		in2[i]=read();
	}
	dfs(1);
	print(ans);
	putchar('\n');
	return 0;
}
