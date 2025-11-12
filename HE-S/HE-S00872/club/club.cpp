#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num[3],Max,Mid,Min;
};
struct node2{
	long long num,id;
};
long long t,n,cnt[3],ans;
node a[100010];
node2 b[3];
bool cmp(node a,node b){
	long long a1=a.num[a.Max],a2=a.num[a.Mid],a3=a.num[a.Min],b1=b.num[b.Max],b2=b.num[b.Mid],b3=b.num[b.Min];
	if(a1-a2!=b1-b2){
		return a1-a2>b1-b2;
	}
	if(a2-a3!=b2-b3){
		return a2-a3>b2-b3;
	}
	if(a1!=b1){
		return a1>b1;
	}
	if(a2!=b2){
		return a2>b2;
	}
	return a3>b3;
}
bool cmp2(node2 a,node2 b){
	return a.num<b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int T=1;T<=t;T++){
		ans=0;
		fill(cnt,cnt+3,0);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i].num[0],&a[i].num[1],&a[i].num[2]);
			b[0].num=a[i].num[0];
			b[1].num=a[i].num[1];
			b[2].num=a[i].num[2];
			b[0].id=0;
			b[1].id=1;
			b[2].id=2;
			sort(b,b+3,cmp2);
			a[i].Min=b[0].id;
			a[i].Mid=b[1].id;
			a[i].Max=b[2].id;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].Max]*2==n){
				if(cnt[a[i].Mid]*2==n){
					cnt[a[i].Min]++;
					ans+=a[i].num[a[i].Min];
				}
				else{
					cnt[a[i].Mid]++;
					ans+=a[i].num[a[i].Mid];
				}
			}
			else{
				cnt[a[i].Max]++;
				ans+=a[i].num[a[i].Max];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
