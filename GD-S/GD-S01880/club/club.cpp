#include<bits/stdc++.h>
#define rg register
#define il inline
using namespace std;
using i64=long long;
il i64 read(){
	i64 x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);x=x*10+(c^48),c=getchar());
	return x;
}
const int maxi=1e5+9;
i64 T,N,FULL,cnt[5],ans;
struct memb{
	i64 a[5];
}a[maxi];
#define step il void
il pair<i64,i64> max1(memb a){
	if(a.a[1]>=a.a[2]&&a.a[1]>=a.a[3])return {a.a[1],1};
	else if(a.a[2]>=a.a[3])return {a.a[2],2};
	else return {a.a[3],3};
}
bool cmp(memb a,memb b){
	return max1(a).first>max1(b).first;
}
bool cmp1(memb a,memb b){
	return a.a[1]+max(b.a[2],b.a[3])>b.a[1]+max(a.a[2],a.a[3]);
}
bool cmp2(memb a,memb b){
	return a.a[2]+max(b.a[1],b.a[3])>b.a[2]+max(a.a[1],a.a[3]);
}
bool cmp3(memb a,memb b){
	return a.a[3]+max(b.a[2],b.a[1])>b.a[3]+max(a.a[2],a.a[1]);
}
namespace T1{
	step clear(){
		for(;N>0;N--)a[N].a[1]=a[N].a[2]=a[N].a[3]=0;
		ans=cnt[1]=cnt[2]=cnt[3]=FULL=0;
		return;
	}
	step getin(){
		N=read();
		for(int i=1;i<=N;i++){
			a[i].a[1]=read();
			a[i].a[2]=read();
			a[i].a[3]=read();
		}
		return;
	}
	step try4(){
		sort(a+1,a+1+N,cmp);
		i64 tpa=0;int i=1;
		for(;i<=N;i++){
			auto tmp=max1(a[i]);
			tpa+=tmp.first;
			cnt[tmp.second]++;
			if(cnt[tmp.second]>=(N/2)){
				FULL=tmp.second;
				for(int j=i+1;j<=N;j++){
					a[j].a[tmp.second]=0;
				}
				sort(a+i+1,a+N+1,cmp);
				i++;
			}
		}	
		for(;i<=N;i++){
			auto tmp=max1(a[i]);
			tpa+=tmp.first;
		}
		ans=max(tpa,ans);
		return;
	}
	step solve(){
		{
			sort(a+1,a+1+N,cmp1);
			i64 tmp=0;
			for(int i=1;i<=N/2;i++){
				tmp+=a[i].a[1];
			}
			for(int i=N/2+1;i<=N;i++){
				tmp+=max(a[i].a[2],a[i].a[3]);
			}
			ans=max(ans,tmp);
		}
		{
			sort(a+1,a+1+N,cmp2);
			i64 tmp=0;
			for(int i=1;i<=N/2;i++){
				tmp+=a[i].a[2];
			}
			for(int i=N/2+1;i<=N;i++){
				tmp+=max(a[i].a[1],a[i].a[3]);
			}
			ans=max(ans,tmp);
		}
		{
			sort(a+1,a+1+N,cmp3);
			i64 tmp=0;
			for(int i=1;i<=N/2;i++){
				tmp+=a[i].a[3];
			}
			for(int i=N/2+1;i<=N;i++){
				tmp+=max(a[i].a[1],a[i].a[2]);
			}
			ans=max(ans,tmp);
		}
		try4();
		return;
	}
	step output(){
		printf("%lld\n",ans);return;
	}
	step init(){
		clear();
		getin();
		solve();
		output();
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(;T--;){
		T1::init();
	}
	return 0;
}
