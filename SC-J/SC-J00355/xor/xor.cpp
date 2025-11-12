#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+9,M=(1<<20)+9;
int a[N];
int sum[N],cnt[M];
int ans=0;
int lst=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		if(cnt[sum[i]^k]){
			++ans;
			for(int j=lst;j<i;j++)
				cnt[sum[j]]=0;
			lst=i;
		}
		cnt[sum[i]]=1;
	}
	printf("%d\n",ans);
}