#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=106;
int n,m;
struct node{
	int a;
	int id;
}p[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&p[i].a);
		p[i].id=i;
	}
	sort(p+1,p+n*m+1,cmp);
	int w;
	for(int i=1;i<=n*m;i++){
		if(p[i].id==1){
			w=i;
			break;
		}
	}
	int cnt=1;
	int x=1,y=1;
	bool fx=0;
	while(cnt<w){
		++cnt;
		if(!fx) ++y;
		else --y;
		if(y==0){
			++y;
			++x;
			fx=0;
		}
		else if(y==m+1){
			--y;
			++x;
			fx=1;
		}
	}
	printf("%d %d\n",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}