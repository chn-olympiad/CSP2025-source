#include<bits/stdc++.h>
using namespace std;
long long n,m,nai[500],ans=1,tp[500];
char s;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("emplay.ans","w",stdout);
	tp[3]=4;
	scanf("%lld %lld",&n,&m);
	scanf("%c",&s);
	for(int i=1;i<=n;i++){
		scanf("%lld",&nai[i]);
	}
	for(int i=4;i<=500;i++)(tp[i]=tp[i-1]*i)%N;
	ans=(tp[n]);
	printf("%lld",ans);
}
