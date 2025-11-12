#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x) {
	x=0;
	char c;
	int sgin=1;
	do {
		c=getchar();
		if(c=='-')sgin=-1;
	} while(!isdigit(c));
	do {
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	} while(isdigit(c));
	x*=sgin;
}
int n,m,cnt,ans;
int x=1,y=1;

void dfs(){
	if(cnt==0)return ;
	if(x%2){
		if(y!=n)y++;
		else x++;
	}
	else{
		if(y!=1)y--;
		else x++;
	}
	cnt--;
	dfs();
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);
	read(m);
	read(ans);
	for(int i=2;i<=n*m;i++){
		int q;
		read(q);
		if(q>ans)cnt++;
	}
	dfs();
	printf("%d %d",x,y);
	return 0;
}
