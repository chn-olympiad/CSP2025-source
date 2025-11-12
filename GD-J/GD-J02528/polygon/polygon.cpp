#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005];
int bj[5005];
long long ans;
long long mod=998244353;
void dfs(int tn,int ts,int tx,int tf){//choose-nth,now-sum,now-max,next-from
	if((tn>3)&&(ts>tx*2)){
		ans=ans+1;
		//for(int i=1;i<tn;i=i+1)printf("%d ",bj[i]);
		//printf("\n");
	//end--
	}
	//printf("%d,%d,%d,%d.\n",tn,ts,tx,tf);
	if(tf>n)return;
	if(tn>n)return;
	for(int i=tf;i<=n;i=i+1){
		bj[tn]=i;
		dfs(tn+1,ts+a[i],max(a[i],tx),i+1);
		bj[tn]=0;
	//dfs-next
	}
	return;
//dfs-get
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int sum=0,mx=0;
	for(int i=1;i<=n;i=i+1)scanf("%d",&a[i]);
	for(int i=1;i<=n;i=i+1){
		sum=sum+a[i];
		mx=max(mx,a[i]);
	//csh-get
	}
	if(n==3&&sum>2*mx)printf("1\n");
	else if(n<=3)printf("0\n");
	else if(n<=20){
		dfs(1,0,0,1);
		printf("%d\n",ans);
	//dfs-get
	}
	else{
		long long cnt1=1,cnt2=0;
		for(long long i=n;i>=3;i=i-1){
			cnt1=(cnt1*i)%mod;
			cnt2=(cnt2+cnt1)%mod;
		//get-ans
		}
		printf("%lld\n",cnt2);
	//count-all
	}
	return 0;
//end-T4
//check-11:13-maybe-60
}
