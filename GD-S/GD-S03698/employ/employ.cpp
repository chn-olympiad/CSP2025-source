#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N],c[N];
int b[N],ans,cnt;
void solve1(){
	for(int i=1;i<=n;i++)
		b[i]=i;
	do{
		cnt=0;
		for(int i=1;i<=n;i++)
			if(!a[i]||cnt>=c[b[i]]) cnt++;
		if(cnt<=n-m) ans++;
	}while(next_permutation(b+1,b+1+n));
	printf("%d",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=10) solve1();
	return 0;
}
