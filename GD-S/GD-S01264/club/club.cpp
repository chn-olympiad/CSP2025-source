#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e5+114;
int cnt1,cnt2,cnt3;
int t,n;
struct hahaha{
	long long a[5];
}a[maxn];
struct nodde{
	int id,minone;
	long long num;
};
bool operator > (nodde xxx,nodde yyy){
	return xxx.num<yyy.num;
}
bool operator < (nodde xxx,nodde yyy){
	return xxx.num>yyy.num;
}
bool operator == (nodde xxx,nodde yyy){
	return xxx.num==yyy.num;
}
bool operator >= (nodde xxx,nodde yyy){
	return xxx.num<=yyy.num;
}
bool operator <= (nodde xxx,nodde yyy){
	return xxx.num>=yyy.num;
}
bool cmp(nodde xxx,nodde yyy){
	return xxx.num<yyy.num;
}
priority_queue<nodde> q[5];
int cnt[5];
long long ans;
void myclear(){
	while(cnt[1]--) q[1].pop();
	cnt[1]=0;
	while(cnt[2]--) q[2].pop();
	cnt[2]=0;
	while(cnt[3]--) q[3].pop();
	cnt[3]=0;
	ans=0;
	return ;
}
void work(int i,int minidd,int idd){
	nodde czx;
	czx.id=i;
	if(cnt[idd]<n/2){
		czx.num=a[i].a[idd]-a[i].a[minidd];
		czx.minone=minidd;
		q[idd].push(czx);
		cnt[idd]++;
		ans+=a[i].a[idd];
	}
	else{
		nodde idk=q[idd].top();
		if(a[i].a[idd]-idk.num>a[i].a[minidd]){
			q[idd].pop();
			czx.num=a[i].a[idd]-a[i].a[minidd];
			czx.minone=minidd;
			q[idd].push(czx);
			ans+=a[i].a[idd]-idk.num;
		}
		else{
			ans+=a[i].a[minidd];
		}
	}
//			printf("%d:%lld\n",i,ans);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		myclear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
			long long maxa=max(a[i].a[1],a[i].a[2]);
			if(maxa<=a[i].a[3]){
				if(a[i].a[1]<=a[i].a[2]) work(i,2,3);
				else work(i,1,3);
			}
			else if(a[i].a[1]<=a[i].a[2]){
				if(a[i].a[1]<=a[i].a[3]) work(i,3,2);
				else work(i,1,2);
			}
			else{
				if(a[i].a[2]<=a[i].a[3]) work(i,3,1);
				else work(i,2,1);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
