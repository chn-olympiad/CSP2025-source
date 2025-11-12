#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;char s[maxn];
int a[maxn],b[maxn];
bool work(){
	//for(int i=1;i<=n;i++) printf("%d ",b[i]);printf("\n");
	int cnt=0;
	for(int i=1,j=i;i<=n;i++,j++) if(cnt<a[b[i]]&&s[j]=='1'){
		;
	}else cnt++;//printf("cnt:%d\n",cnt);
	return n-cnt>=m;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=i;
	int ans=0;
	do ans+=work();while(next_permutation(b+1,b+n+1));
	printf("%d\n",ans);
	return 0;
}
