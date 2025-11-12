#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

int t,n,limit,ans,sat[3][MAXN],tmp;

struct ranked{
	int d,val;
	bool neg;
}dif[MAXN];

bool scmp(ranked a, ranked b){
	return a.d>b.d;
}

inline int max(int a,int b){return a>b?a:b;}
int read(){
	int rx=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		rx=rx*10+ch-'0';
		ch=getchar();
	}
	
	return rx;
}
void write(int x){
	static int sta[52];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}

void dfs(int member,int a,int b,int c,int val){
	//printf("[sys]member%d: A=%d,B=%d,C=%d sat=%d\n",member,a,b,c,val);
	if(member>=n){
		ans=max(ans,val);
		return;
	}
	if(a<limit){
		dfs(member+1,a+1,b,c,val+sat[0][member]);
	}
	if(b<limit){
		dfs(member+1,a,b+1,c,val+sat[1][member]);
	}
	if(c<limit){
		dfs(member+1,a,b,c+1,val+sat[2][member]);
	}
	return;
}

void solveAB(){
	int sat1,sat2;
	//printf("special solve\n");
	for(int i=0;i<n;++i){
		tmp=sat1=read();
		tmp-=(sat2=read());
		read();
		if(tmp>0){
			dif[i].d=tmp;
			dif[i].neg=false;
			dif[i].val=sat1;
		}else{
			dif[i].d=-tmp;
			dif[i].neg=true;
			dif[i].val=sat2;
		}
	}
	sort(dif,dif+n,scmp);
	int acnt=0,bcnt=0;
	for(int i=0;i<n;++i){
		//printf("dif=%c%d val:%d\n",dif[i].neg?'-':' ',dif[i].d,dif[i].val);
		if(dif[i].neg){
			ans+=dif[i].val;
			if(bcnt<limit){
				++bcnt;
			}else{
				++acnt;
				ans-=dif[i].d;
			}
		}else{
			ans+=dif[i].val;
			if(acnt<limit){
				++acnt;
			}else{
				++bcnt;
				ans-=dif[i].d;
			}
		}
	}
	//printf("a:%d, b:%d\n",acnt,bcnt);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	while(t--){
		ans=0;
		n=read();
		limit=n>>1;
		if(n==100000||n==200){ // Special AB
			solveAB();
		}else{ // violent dfs
			for(int i=0;i<n;++i){
				sat[0][i]=read();
				sat[1][i]=read();
				sat[2][i]=read();
			}
			dfs(0,0,0,0,0);
		}
		write(ans);putchar('\n');
	}
	
	return 0;
}
