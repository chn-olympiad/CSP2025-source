#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,MOD=998244353;
long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
long long ad(int x){
	int an=1;
	for(int i=1;i<=x;i++){
		an=(an*2)%MOD;
	}
	return an;
}
long long n,a[N],s[N],ans;
void dfs(int dep,int sgml,int maxl){
	if(sgml>maxl){
		ans=(ans+ad(dep))%MOD;
		return;
	}
	if(dep==0||s[dep]+sgml<=maxl) return;
	dfs(dep-1,sgml+a[dep],maxl);
	dfs(dep-1,sgml,maxl);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	long long maxa=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxa==1){
		ans=(ans+ad(n))%MOD;
		ans=(ans-n+MOD)%MOD;
		ans=(ans-n*(n-1)/2+MOD)%MOD;
	}else{
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		for(int i=3;i<=n;i++){
			dfs(i-1,0,a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
