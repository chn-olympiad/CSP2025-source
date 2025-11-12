#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
void rd(T &s){
	s=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+(c-48);
		c=getchar();
	}
}
const int N=505,mod=998244353;
int n,m,c[N];
char s[N];
int p[N],ans;
bool check(){
	int fail=0,se=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') fail++;
		else if(s[i]=='1'&&fail<c[p[i]]) se++;
		else fail++;
	}
	if(se>=m) return true;
	else return false;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	rd(n),rd(m);
	scanf(" %s",s+1);
	for(int i=1;i<=n;i++) rd(c[i]);
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		if(check()) ans++;
		if(ans>=mod) ans-=mod;
	}while(next_permutation(p+1,p+1+n));
	printf("%d",ans);
	return 0;
}
