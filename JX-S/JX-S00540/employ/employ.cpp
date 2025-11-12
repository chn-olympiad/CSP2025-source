#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
inline void printt(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) printt(x/10);
	putchar(x%10+'0');
}
inline void print(int x){
	printt(x);
	puts("");
}
inline int read(){
	char c;
	int res=0,flag=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			flag=-1;
			c=getchar();
			break;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
const int P=998244353;
const int N=5e2+1;
int n,m,c[N],cnt=0,num[N],ans=0;
char s[N];
bool vis[N];
inline bool check(int num[]){
	memset(vis,0,sizeof(vis));
	int peo=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||vis[num[i]]==1){
			peo++;
			for(int j=i+1;j<=n;j++){
				if(c[num[j]]<=peo) vis[num[j]]=1;
			}
			continue;
		}
		vis[num[i]]=1;
		cnt++;
	}
	return cnt>=m;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s);
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1') cnt++;
	}
	if(cnt==n||m==1){
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%P;
		print(ans);
		return 0;
	}
	for(int i=1;i<=n;i++) num[i]=i;
	do{
		if(check(num)){
			ans=(ans+1)%P;
			//for(int i=1;i<=n;i++) printf("%lld ",num[i]);
			//puts("");
			//wcnm,sbccf
		}
	}while(std::next_permutation(num+1,num+n+1));
	print(ans);
	return 0;
}

