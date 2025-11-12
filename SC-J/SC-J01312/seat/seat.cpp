#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(ll x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
int n,m,tot;
struct node{
	bool r;
	int x;
	bool operator<(const node &p)const{
		return x<p.x;
	}
}a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[++tot]={(i==1 and j==1),read()};
	sort(a+1,a+tot+1);
	int f=0;
	for(int i=1;i<=tot;++i)
		if(a[i].r==1)
			f=i;
	f=tot-f+1;
	int h=(f-1)%n+1,l=(f-1)/n+1;
	if(l%2==0)
		h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
}
/*
对拍了7000组，
这题包满分的啊

此题每挂1分，我围着操场跑10圈


盗号诗 - QMR
盗到号了叫盗号霖，
没盗到号叫招笑霖。
你若嘲笑这赵浩霖，
下个机惨的就是您。
*/