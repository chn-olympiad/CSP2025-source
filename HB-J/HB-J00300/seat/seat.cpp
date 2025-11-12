#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

int n,m,fd,score[105];

bool cmp(int a,int b) {return a>b;}
int read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-48),ch=getchar();
	return x*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	n=read(),m=read()*n;
	for(int i=1;i<=m;i++) score[i]=read();
	fd=score[1];
	sort(score+1,score+m+1,cmp);
	for(int i=1;i<=m;i++) if(score[i]==fd){
		int l=(i-1)/n+1;
		if(l&1) printf("%d %d\n",l,((i-1)%n)+1);
		else printf("%d %d\n",l,n-((i-1)%n));
		break;
	}
	return 0;
}