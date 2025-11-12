#include<iostream>
using namespace std;
const int maxa=5000+5;
int n,ans=0;
int cnt[maxa];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=n;i++){
		int maxlen=2*i;
		for(int j=1;j<i;j++){
			int k=(maxlen-1/j)+1;//至少要 k 条长度为 j 的边
			k=max(2,k);//多边形边数>=3
			if(cnt[j]>=k)ans+=cnt[j]-k+1;
		}
		if(cnt[i]>=3)ans+=cnt[i]-2;//至少选三条一样的边
	}
	printf("%d",ans); 
	return 0;
}
