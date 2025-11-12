#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=19;
int s[N];
int c[N];
int p[N];
int jc[N];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),p[i]=i;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i;
	for(int i=1;i<=jc[n];i++){
		int cnt=0,sum=0;
		for(int j=1;j<=n;j++){
			if(cnt>=c[p[j]])++cnt;
			else if(s[j])sum++;
			else cnt++;
		}
		if(sum>=m)++ans;
		next_permutation(p+1,p+n+1);
	}
	printf("%d\n",ans);
	
}