#include<bits/stdc++.h>
#define int long long
#define rd() read()
#define wt write
#define pc putchar
using namespace std;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-'){
				f=-1;
			}
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<1)+(x<<3)+(c^48);
			c=getchar();
		}
		return x*f;
	}
	inline void write(int x){
		if(x<0){
			x=-x;
			pc('-');
		}
		if(x>9){
			write(x/10);
			pc(x%10+'0');
		}
		else{
			pc(x+'0');
		}
		return ;
	}
}
using namespace IO;
namespace Main{
	const int N=510,MOD=998244353;
	int n,m,res;
	int c[N],t[N];
	char s[N];
	int flac[N]={1};
	inline void init(){
		for(int i=1;i<=500;i++){
			flac[i]=i%MOD*flac[i-1]%MOD;
//			if(flac[i]%161088479==0||161088479%flac[i]==0){
//				cout<<"i="<<i<<endl;
//			}
		}
		return ;
	}
	inline void main(){
		init();
		n=rd(),m=rd();
		scanf("%s",s+1);
		bool flag=1;
		int zero=0;
		for(int i=1;i<=n;i++){
			c[i]=rd();
//			if(!(s[i]-'0')){
//				c[i]=0;
//			}
			zero+=(!c[i]);
		}
		sort(c+1,c+n+1);
//		for(int i=1;i<=n;i++){
//			cout<<c[i]<<' ';
//		}
//		puts("");
//		cout<<"zero="<<zero<<'\n';
		for(int i=1;i<=n;i++){
			if(!(s[i]-'0')){
				flag=0;
				break;
			}
		}
		if(flag&&(!zero)){
			wt(flac[n-zero]);
			return ;
		}
		if(m==1){
			
		}
//		if(n<=15){
			for(int i=1;i<=n;i++){
				t[i]=i;
			}
			do{
				int ok=0,no=0;
				for(int i=1;i<=n;i++){
					if(no>=c[t[i]]){
						no++;
						continue;
					}
					if(s[i]=='1'){
						ok++;
					}
					else{
						no++;
					}
				}
				res+=(ok>=m);
				res%=MOD;
			}while(next_permutation(t+1,t+n+1));
			wt(res%MOD);
//		}
		return ;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Main::main();
	return 0;
}

