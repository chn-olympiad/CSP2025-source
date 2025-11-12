#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
inline void read(int& x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	x*=f;
}
const int N=500+10,mod=998244353;
int pw[N];
int c[N],buc[N],b[N];
char s[N];
int n,m,one=0;
bool check(vector<int>& v){
	int cnt=0,zero=0;
	for(int i=0;i<v.size();i++){
		if(s[i+1]=='0')zero++;
		else if(s[i+1]=='1'){
			if(c[v[i]]>zero)cnt++;
			else zero++;
		}
	}
	return zero>=m;
}
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	read(n),read(m);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*i%mod;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)one+=s[i]-'0';
	for(int i=1;i<=n;i++)read(c[i]),buc[c[i]]++;
	for(int i=1;i<=n;i++)b[i]=b[i-1]+buc[i];
	if(m==1){
		int cnt=buc[0],res=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1')res*=cnt,res%=mod,cnt--;
			cnt+=buc[i];
		}
		res=res*pw[n-one]%mod;
		printf("%lld",((pw[n]-res)%mod+mod)%mod);
		return 0;
	}
	else if(m==n){
		bool f=one<n;
		for(int i=1;i<=n;i++){
			if(!c[i])f=0;
		}
		if(f)printf("%lld",pw[n]);
		else puts("0");
		return 0;
	}
	vector<int> vec;
	int cnt=0;
	for(int i=1;i<=n;i++){
		vec.push_back(i);
	}
	do{
		cnt+=check(vec);
	}while(next_permutation(vec.begin(),vec.end()));
	printf("%lld",cnt);
}
/*

*/
