#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=5e6+5,base1=37,mod1=998244353,base2=233,mod2=147744151;
inline int Mod1(int x){return x>=mod1?x-mod1:x;}
inline int Mod2(int x){return x>=mod2?x-mod2:x;}
int n,q;
map<pair<pair<int,int>,pair<int,int>>,int>cnt;
char t[2][N];
void INPUT(){
	while(n--){
		char ch=getchar();
		int len0=0,len1=0;
		while(ch<'a'||'z'<ch)ch=getchar();
		while('a'<=ch&&ch<='z'){
			t[0][++len0]=ch;
			ch=getchar();
		}
		while(ch<'a'||'z'<ch)ch=getchar();
		while('a'<=ch&&ch<='z'){
			t[1][++len1]=ch;
			ch=getchar();
		}
		int len=len0;
		int s11=0,s12=0,s21=0,s22=0;
		for(int i=1;i<=len;i++){
			s11=Mod1(1ll*base1*s11%mod1+t[0][i]-'a'+1);
			s12=Mod2(1ll*base2*s12%mod2+t[0][i]-'a'+1);
			
			s21=Mod1(1ll*base1*s21%mod1+t[1][i]-'a'+1);
			s22=Mod2(1ll*base2*s22%mod2+t[1][i]-'a'+1);
		}
		cnt[{{s11,s12},{s21,s22}}]++;
	}
}
void sol(){
	char ch=getchar();
	int len0=0,len1=0;
	while(ch<'a'||'z'<ch)ch=getchar();
	while('a'<=ch&&ch<='z'){
		t[0][++len0]=ch;
		ch=getchar();
	}
	while(ch<'a'||'z'<ch)ch=getchar();
	while('a'<=ch&&ch<='z'){
		t[1][++len1]=ch;
		ch=getchar();
	}
	if(len0!=len1){
		printf("0\n");
		return;
	}
	int len=len0;
	int R=1,L=len;
	for(int i=1;i<=len;i++)
		if(t[0][i]!=t[1][i])
			R=i;
	for(int i=len;i>=1;i--)
		if(t[0][i]!=t[1][i])
			L=i;
	ll ans=0;
	for(int l=1;l<=L;l++){
		int s11=0,s12=0,s21=0,s22=0;
		for(int r=l;r<=len;r++){
			s11=Mod1(1ll*base1*s11%mod1+t[0][r]-'a'+1);
			s12=Mod2(1ll*base2*s12%mod2+t[0][r]-'a'+1);
			
			s21=Mod1(1ll*base1*s21%mod1+t[1][r]-'a'+1);
			s22=Mod2(1ll*base2*s22%mod2+t[1][r]-'a'+1);
			if(r>=R)ans+=cnt[{{s11,s12},{s21,s22}}];
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	INPUT();
	while(q--)sol();
	return 0;
}

