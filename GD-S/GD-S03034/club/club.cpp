#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

struct my{
	int a,b,c;
}q[200010];
long long ans;
int n,x,y,z;

void dfs(int k,long long p){
	if(k>n){
		if(p>ans)ans=p;
		return;
	}
	if(x<n/2){
		x++;
		dfs(k+1,p+q[k].a);
		x--;
	}
	if(y<n/2){
		y++;
		dfs(k+1,p+q[k].b);
		y--;
	}
	if(z<n/2){
		z++;
		dfs(k+1,p+q[k].c);
		z--;
	}
}
void dfs1(int k,long long p){
	if(k>n){
		if(p>ans)ans=p;
		return;
	}
	if(x<n/2){
		x++;
		dfs(k+1,p+q[k].a);
		x--;
	}
	if(y<n/2){
		y++;
		dfs(k+1,p+q[k].b);
		y--;
	}
}

bool cmp1(my a,my b){
	return a.a>b.a;
}
bool cmp2(my a,my b){
	return a.b>b.b;
}
bool cmp3(my a,my b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		ans=0;
		n=read();
		bool A=true,B=true,C=true;
		for(int i=1;i<=n;i++){
			q[i].a=read();
			if(q[i].a!=0)A=false;
			q[i].b=read();
			if(q[i].b!=0)B=false;
			q[i].c=read();
			if(q[i].c!=0)C=false;
		}
		if(A&&C){
			sort(q+1,q+1+n,cmp2);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].b;
			}
		}
		else if(B&&C){
			sort(q+1,q+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].a;
			}
		}
		else if(A&&B){
			sort(q+1,q+1+n,cmp3);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].c;
			}
		}
		else if(C&&0){
			dfs1(1,0); 
		}
		else {
			dfs(1,0);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 

