#include <bits/stdc++.h>
const int N=2e5+10,M=5e6+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,q;
int len[N];
ll ans;
char s1[M],s2[M],t1[M],t2[M];
ull h1[N],h2[N],ht1[M],ht2[M];
void calc1(int pos){
	ull res1[M],res2[M];
	res1[0]=0,res2[0]=0;
	m=strlen(s1+1);
	len[pos]=m;
	for(int i=1;i<=m;i++){
		res1[i]=res1[i-1]+s1[i]*131;
		res2[i]=res2[i-1]+s2[i]*131;
	}
	h1[pos]=res1[m],h2[pos]=res2[m];
}
void init(){
	ans=0;
	ht1[0]=ht2[0]=0;
	m=strlen(t1+1);
	for(int i=1;i<=m;i++){
		ht1[i]=ht1[i-1]+t1[i]*131;
		ht2[i]=ht2[i-1]+t2[i]*131;
	}
}
void calc2(int pos){
	for(int i=1;i<=m-len[pos]+1;i++)
		if(ht1[i+len[pos]-1]-ht1[i-1]==h1[pos]&&ht1[m]-(ht1[i+len[pos]-1]-ht1[i-1])+h2[pos]==ht2[m])
			ans++;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		calc1(i);
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		init();
		for(int i=1;i<=n;i++)
			calc2(i);
		printf("%lld\n",ans);
	}
	return 0;
}
