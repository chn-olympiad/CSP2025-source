#include <bits/stdc++.h>

using namespace std;

const int maxn=505;
int p[maxn],c[maxn],n,m,cnt1=0;
char ch[maxn];

namespace Sub1{
	void solve(){
		for(int i=1;i<=n;i++) p[i]=i;
		int res=0;
		do{
			int tt=0,tp=0;
			for(int i=1;i<=n;i++){
				if(c[p[i]]<=tp){
					tp++;
					continue;
				}
				if(ch[i]=='0'){
					tp++;
					continue;
				}
				tt++;
			}
			if(tt>=m) res++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",res);
	}
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d %d %s",&n,&m,ch+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		cnt1+=(ch[i]=='1');
	}
	
	if(m>cnt1){
		puts("0");
		return 0;
	}
	
	if(n<=10) Sub1::solve();
	
	return 0;
}