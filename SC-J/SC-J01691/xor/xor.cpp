#include <bits/stdc++.h>
using namespace std;
const int maxn=114514;
struct node{
	int L,R;
}c[maxn];
int s[maxn],a[maxn],last=0,cnt=0,ans=0,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==k) c[++cnt].L=l,c[cnt].R=r;
		}
	}
	//for(int i=1;i<=cnt;i++) printf("%d %d\n",c[i].L,c[i].R);
	for(int i=1;i<=cnt;i++){
		if(c[i].L!=c[i-1].L && c[i].L>c[last].R){
			last=i;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}