#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iostream>
#include<string.h>
#include<time.h>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<random>
using std::cin;
using std::cout;
using std::string;
#define ci const int
#define iv inline void
#define ic inline ci
#define ll long long
#define ull unsigned ll
//#define int ll
#define gc getchar_unlocked
#define pc putchar
#define mod1 879348829ull
ic re();iv pr(ci x);iv prs(ci x);iv prn(ci x);
iv swp(int&a,int&b){a^=b^=a^=b;}
ic Max(ci a,ci b){return a>b?a:b;}
ic Min(ci a,ci b){return a<b?a:b;}
iv gma(int&a,ci b){a=Max(a,b);}
iv gmi(int&a,ci b){a=Min(a,b);}
ic Abs(ci a){return a<0?-a:a;}
#define L 5000003
#define N 200003
int n,q;
// ull pw1[L],pw2[L];
// ci B1=137,B2=157;
// ull h1[L],h2[L];
// ull len[N],sh[N][2],th[N][2];
string s1,s2,s[N],t[N];
// #define pii std::pair<ull,ull>
// #define mp std::make_pair
// std::map<pii,int>MP;
// std::vector<pii >v[N];
// int tp;
iv work(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n>=200&&q>=200){
		while(q--)cout<<"0\n";
		return;
	}
	// pw1[0]=pw2[0]=1;
	// for(int i=1;i<=5000000;++i)
	// 	pw1[i]=pw1[i-1]*B1,
	// 	pw2[i]=pw2[i-1]*B2%mod1;
	for(int i=1;i<=n;++i){
		//cin>>s1>>s2;
		cin>>s[i]>>t[i];
		// len[i]=s1.size();
		// for(int j=0;j<len[i];++j)
		// 	sh[i][0]+=pw1[j]*s1[j],
		// 	th[i][0]+=pw1[j]*s2[j],
		// 	sh[i][1]=(sh[i][1]+pw2[j]*s1[j])%mod1,
		// 	th[i][1]=(th[i][1]+pw2[j]*s2[j])%mod1;
		// const pii psp=mp(sh[i][0],sh[i][1]);
		// const pii ptp=mp(th[i][0],th[i][1]);
		// if(!MP.count(psp))MP[psp]=++tp;
		// v[MP[psp]].push_back(ptp);
	}
	for(int val;q--;){
		cin>>s1>>s2;val=0;
		if(s1.size()!=s2.size()){
			cout<<"0\n";continue;
		}int sz=s1.size(),wow1=0,wow2=0;
		for(int i=0;i<sz;++i)
			if(s1[i]!=s2[i]){wow1=i;break;}
		for(int i=sz-1;~i;--i)
			if(s1[i]!=s2[i]){wow2=i+1;break;}
		for(int i=1,x,y;i<=n;++i){
			x=s1.find(s[i]);
			y=s2.find(t[i]);
			if(~x&&~y&&x==y&&x<=wow1&&x+s[i].size()>=wow2)
				++val;//,cout<<x<<' '<<wow1<<' '<<x+s[i].size()<<' '<<wow2<<'\n';
			//if(~x&&~y&&x==y&&s1.substr(0,x)==s2.substr(0,x)&&s1.substr(x+s[i].size())==s2.substr(x+s[i].size()))
			//	++val;
		}cout<<val<<'\n';
	}
}
/*
ulimit -s 10240
10 MB

117 min
2/20
*/
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int T=1||re();T--;)work();
}
ic re(){
	int x=0;char c=gc(),f=0;
	while(c<48||c>57)f|=(c=='-'),c=gc();
	while(c<58&&c>47)x=x*10+(c^48),c=gc();
	return f?-x:x;
}
void pri(ci x){if(x>9)pri(x/10);pc(x%10^48);}
iv pr(ci x){if(x<0)pc('-'),pri(-x);else pri(x);}
iv prs(ci x){pr(x),pc(32);}
iv prn(ci x){pr(x),pc(10);}
/*
g++ -Wall -Wextra -O2 1.cpp -o 1
g++ -Wall -Wextra -O2 2.cpp -o 2
g++ -Wall -Wextra -O2 3.cpp -o 3
g++ -Wall -Wextra -O2 4.cpp -o 4
./1
./2
./3
./4
Ren5Jie4Di4Ling5%
*/