#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
inline int read(){
	int f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
int T,n,ans;
struct ele{
	int a,b,c;
}s[N];
bool cmpa(ele A,ele B){
	if(A.a == B.a) return A.b > B.b; 
	return A.a > B.a;
}
void dfs(int u,int sum,int sa,int sb,int sc){
	if(u > n){
		ans = max(ans,sum);
		return ;
	}
	if(sa < n / 2){
		dfs(u + 1,sum + s[u].a,sa + 1,sb,sc);
	}
	if(sb < n / 2){
		dfs(u + 1,sum + s[u].b,sa,sb + 1,sc);
	}
	if(sc < n / 2){
		dfs(u + 1,sum + s[u].c,sa,sb,sc + 1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		ans = 0;
		bool fl2 = 0,fl3 = 0;
		for(int i = 1;i <= n;i++){
			s[i].a = read(),s[i].b = read(),s[i].c = read();
			if(s[i].b > 0) fl2 = 1;
			if(s[i].c > 0) fl3 = 1;
		}
		if(!fl2 && !fl3){ 
			sort(s + 1,s + 1 + n,cmpa);
			for(int i = 1;i <= n / 2;i++){
				ans += s[i].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
