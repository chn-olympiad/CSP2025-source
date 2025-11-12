#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
#define rgt register
const int N = 503,mod=998244353;
int n,m,cnt,fail,ans;
char s[N];int c[N],tmp[N];

bool checkA(){
	for(rgt int i=1;i<=strlen(s+1);++i)
		if(s[i]=='0')
			return false;
	return true;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(rgt int i=1;i<=n;++i) scanf("%d",&c[i]),tmp[i]=i;
	if(checkA()){
		ll res=1;
		for(int i=2;i<=n;++i)
			res=res*i%mod;
		ans = res;
	}else{
		do{
			cnt = 0;fail = 0;
			for(rgt int i=1;i<=n;++i){
				if(fail>=c[tmp[i]]){
					++fail;
				}else if(s[i]=='0'){
					++fail;
				}else{
					++cnt;
				}
			}
			if(cnt>=m) ans=(ans+1)%mod;
		}while(next_permutation(tmp+1,tmp+n+1));
	}
	cout << ans;
	return 0;
}
