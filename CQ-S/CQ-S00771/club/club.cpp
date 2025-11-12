#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
int N,a[maxn][4],cnt[4],ans;
int b[maxn],c[maxn],tot;
inline void solve(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
	ans=0;cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=N;i++){
		if(a[i][1]>=max(a[i][2],a[i][3]))ans+=a[i][1],cnt[1]++,b[i]=1;
		else if(a[i][2]>=max(a[i][1],a[i][3]))ans+=a[i][2],cnt[2]++,b[i]=2;
		else if(a[i][3]>=max(a[i][1],a[i][2]))ans+=a[i][3],cnt[3]++,b[i]=3;
	}
	int inx,mx=0;
	for(int i=1;i<=3;i++)if(cnt[i]>mx)mx=cnt[i],inx=i;
	if(mx<=N/2){printf("%d\n",ans);return;}
	tot=0;
	for(int i=1;i<=N;i++){
		if(b[i]==inx){
			if(inx==1)c[++tot]=max(a[i][2],a[i][3])-a[i][1];
			if(inx==2)c[++tot]=max(a[i][1],a[i][3])-a[i][2];
			if(inx==3)c[++tot]=max(a[i][2],a[i][1])-a[i][3];
		}
	}
	
	sort(c+1,c+tot+1);
	for(int i=tot;tot-i+1<=(mx-(N/2));i--)ans+=c[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	int TTT;scanf("%d",&TTT);while(TTT--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
