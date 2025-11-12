//为什么要攀登？因为山就在那里。 
#include<bits/stdc++.h>
#define mrx 0x3f3f3f3f3f3f3f3f
#define int unsigned long long
using namespace std;
inline int read(){
	int num=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar(); 
	}
	return num*flag;
}
char wshthxdsdg[40];
inline void write(int num){
	int flag=0;
	if(!num) return putchar('0'),void();
	if(num<0) putchar('-'),num=-num;
	while(num){
		wshthxdsdg[++flag]=((num%10)^48);
		num/=10;
	}
	for(int i=flag;i;i--) putchar(wshthxdsdg[i]);
}
inline void out(int num){
	write(num);
	putchar(' ');
}
inline void print(int num){
	write(num);
	putchar('\n');
}
inline int ksm(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
const int base=19260817;
int n,_;
string s[2];
map<pair<int,int>,int > mp;
int Hash1[2000010];
int Hash2[2000010];
int exp_base[2000010];
int ha1(int l,int r){
	return Hash1[r]-Hash1[l-1]*exp_base[r-l+1];
}
int ha2(int l,int r){
	return Hash2[r]-Hash2[l-1]*exp_base[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),_=read();
	for(int i=1;i<=n;i++){
		cin>>s[0]>>s[1];
		int len=s[0].size();
		s[0]=' '+s[0];
		s[1]=' '+s[1];
		int hash1=0,hash2=0;
		for(int j=1;j<=len;j++){
			hash1=(hash1*base+s[0][j]);
			hash2=(hash2*base+s[1][j]);
		}
		mp[{hash1,hash2}]++;
	}
	exp_base[0]=1;
	for(int i=1;i<=2e6;i++) exp_base[i]=exp_base[i-1]*base;
	for(int i=1;i<=_;i++){
		string x,y;
		cin>>x>>y;
		int k=x.size();
		x=' '+x;y=' '+y;
		if(x.size()!=y.size()) print(0);
		else{
			int ans=0;
			for(int i=1;i<=k;i++){
				Hash1[i]=Hash1[i-1]*base+x[i];
				Hash2[i]=Hash2[i-1]*base+y[i];
			}
			int start=1,last=k;
			for(int i=1;i<=k;i++){
				if(x[i]!=y[i]){
					start=i;
					break;
				}
			}
			for(int i=k;i>=1;i--){
				if(x[i]!=y[i]){
					last=i;
					break;
				}
			}
			for(int i=1;i<=start;i++){
				for(int j=last;j<=k;j++){
					int now=ha1(i,j),to=ha2(i,j);
//					cout<<now<<' '<<to<<'\n';
					ans+=mp[{now,to}];
				} 
			}
			print(ans);
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
