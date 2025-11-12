#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1025*1025;
int a[N],s[N],maxn[N];
int n,k,l=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=a[i]^s[i-1];
		//cout<<maxn[(s[i]^k)]<<' '<<l<<'\n';
		if(maxn[s[i]^k]>=l&&((s[i]^k)==0||maxn[s[i]^k]!=0))l=i,ans++;
		maxn[s[i]]=i;
	}
	printf("%d",ans);
	return 0;
}
/*
2
1 3 2 4 1 2 2 3 
--- -   -------
          - -
10
1 3
2 2
3 4
5 6
4 6
3 7
7 9
8 9
6 10
1 2 3 4 5 6 7 8 9 10
1 3
4 6
3 4
2
3 1 0 0 0 0 0 0 0 0
*/
