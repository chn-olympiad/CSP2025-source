#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;
int dis[N];char a[N];

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
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9') dis[++cnt]=a[i]-'0';
	}
	sort(1+dis,1+dis+cnt);
	for(int i=cnt;i>=1;i--) write(dis[i]);
	return 0;
}
