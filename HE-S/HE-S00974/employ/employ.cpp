#include<cstdio>
#include<algorithm>
int n,m;
char s[505];
int c[505];
int p[505];
const int mod=998244353;
int ans;
bool ok(){
	int x=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||x>=c[p[i]]){
			x++;
		}
	}
	return n-x>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		p[i]=i;
	}
	do{
		if(ok()){
			ans++;
			if(ans==mod){
				ans=0;
			}
		}
	}while(std::next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
}
