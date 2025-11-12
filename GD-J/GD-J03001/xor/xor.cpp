#include<bits/stdc++.h>
#define ll long long
#define N 1200005
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;
int dis[N];
unordered_map<int,bool> f;

void read(int &x){
	x=0;int ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(int x){
	if(x<0){
		putchar('-');x=-x;
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(m);f[0]=1;
	for(int i=1;i<=n;i++) read(dis[i]);
	for(int i=1;i<=n;i++){
		ans^=dis[i];
		if(f[ans^m]){
			ans=0,sum++;
			f.clear();f[0]=1;
		}
		else f[ans]=1;
	}write(sum);
	return 0;
}/*

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

*/
