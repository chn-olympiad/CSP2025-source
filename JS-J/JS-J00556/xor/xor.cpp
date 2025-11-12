#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,end=0,ans=0,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if((mp[sum^k]>end)||(!(sum^k)))ans++,end=i,sum=0;
		mp[sum]=i;
	}
	printf("%d",ans);
	return 0;
}
/*
4 3
2 1 0 3
 */
