#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int a[N][3],mx[N];
int cnt[3];
int val[N];
void work(){
	cnt[0]=cnt[1]=cnt[2]=0;
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>a[i][mx[i]]) mx[i]=j;
		}
		cnt[mx[i]]++;
		sum+=a[i][mx[i]];
	}
	int mxid=0,tot=0;
	for(int i=0;i<3;i++) if(cnt[mxid]<cnt[i]) mxid=i;
	for(int i=1;i<=n;i++) if(mx[i]==mxid){
		val[++tot]=max(a[i][(mxid+1)%3],a[i][(mxid+2)%3])-a[i][mxid];
	}
	sort(val+1,val+tot+1);
	for(int i=tot;i>n/2;i--) sum+=val[i];
	printf("%d\n",sum);
	for(int i=0;i<=n;i++) mx[i]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--) work();
	return 0;
}