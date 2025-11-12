#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],ans;
char c[5010];
bool b[5010];
inline int jiecheng(int x){
	int s=1;
	for(int i=1;i<=x;i++)s=s*i%998244353;
	return s;
}
inline void dfs(int day,int no,int pass){
	if(pass==m){
		ans=(ans+jiecheng(n-day+1))%998244353;
		cout<<ans<<"\n";
		return;
	}
	if(day>n)return;
	no+='1'-c[day];
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(a[i]<=no)no++;
			else if(c[day]-'0')pass++;
			else no++;
			dfs(day+1,no,pass);
		}
		b[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,c+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
