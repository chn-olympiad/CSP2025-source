#include<bits/stdc++.h>
using namespace std;
long long ans,cnt[5],n,T,biao1,biao2,sum;
struct aty{
	long long x,y,z,maxn,minn,mid,posmaxn,posminn,posmid;
}a[100010];
long long cmp(aty a,aty b){
	if(a.maxn==b.maxn){
		if(a.mid==b.mid) return a.minn<b.minn;
		else return a.mid<b.mid;
	}else return a.maxn>b.maxn;
}
long long cmp1(aty a,aty b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x>b.x;
}

long long cmp2(aty a,aty b){
	if(a.y==b.y) return a.x<b.x;
	return a.y>b.y;
}

void dfs(long long k,long long sum){
	if(k==n+1){
		ans=max(ans,sum);
		return ;
	}
	
	if(cnt[1]<n/2) {
		cnt[1]++;
		dfs(k+1,sum+a[k].x);
		cnt[1]--;
	}
	if(cnt[2]<n/2) {
		cnt[2]++;
		dfs(k+1,sum+a[k].y);
		cnt[2]--;
	}
	if(cnt[3]<n/2) {
		cnt[3]++;
		dfs(k+1,sum+a[k].z);
		cnt[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		scanf("%lld",&n);
		biao1=biao2=1;
		ans=sum=0;
		for(long long i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y!=0) biao1=0;
			if(a[i].z!=0) biao2=0;
			
			a[i].maxn=max(max(a[i].x,a[i].y),a[i].z);
			
			a[i].minn=min(min(a[i].x,a[i].y),a[i].z);
			if(a[i].maxn==a[i].minn) {
				a[i].posmaxn=1;
				a[i].posmid=2;
				a[i].posminn=3;
			}else{
				if(a[i].maxn==a[i].x) a[i].posmaxn=1;
				if(a[i].maxn==a[i].y) a[i].posmaxn=2;
				if(a[i].maxn==a[i].z) a[i].posmaxn=3;
				
				if(a[i].minn==a[i].x) a[i].posminn=1;
				if(a[i].minn==a[i].y) a[i].posminn=2;
				if(a[i].minn==a[i].z) a[i].posminn=3;
				a[i].posmid=6-a[i].posmaxn-a[i].posminn;
			}
			a[i].mid=a[i].x+a[i].y+a[i].z-a[i].maxn-a[i].minn;
		}
		if(biao1==1&&biao2==1){
			sort(a+1,a+1+n,cmp1);
			for(long long i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<endl;
			continue;
		}
		
		dfs(1,0);
		cout<<ans<<endl; 
	/*	if(biao2==1){
			sort(a+1,a+1+n,cmp1);
			for(long long i=1;i<=n;i++){
				if(i<=n/2)
				   ans+=a[i].x;
				else ans+=a[i].y;
			}
			sum=0;
			sort(a+1,a+1+n,cmp2);
			for(long long i=1;i<=n;i++){
				if(i<=n/2)
				   sum+=a[i].y;
				else sum+=a[i].x;
			}
			cout<<max(sum,ans)<<endl;
			
		}
	/*	sort(a+1,a+1+n,cmp);
		ans=0;
		for(long long i=1;i<=n;i++){
			if(cnt[a[i].posmaxn]<n/2){
				cnt[a[i].posmaxn]++;
				ans+=a[i].maxn;
			}else if(cnt[a[i].posmid]<n/2){
				cnt[a[i].posmid]++;
				ans+=a[i].mid;
			}else {
				cnt[a[i].posminn]++;
				ans+=a[i].minn;
			}
		}
		prlong longf("%lld\n",ans);*/
	}
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
