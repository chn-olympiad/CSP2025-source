#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int t,n,a[N][4];

int dp[N],ans=-1;

int cnt[4];
struct fake{
	int a1,a2,a3;
}r[N];

struct node{
	int dat,id;
	bool operator<(const node&x) const 
      { return x.dat < dat; }
};

priority_queue<node>q[4];

void clear(){
	for(int i=1;i<=3;i++){
		while(!q[i].empty())q[i].pop();
		//memset(cnt[i],0,sizeof(cnt[i]));
	}
	cnt[1]=cnt[2]=cnt[3]=0;
}

void get(int i,int now,int cnt1,int cnt2,int cnt3){
	if(i>n){
		ans=max(ans,now);
		return;
	}
	if(cnt1<n/2)
		get(i+1,now+a[i][1],cnt1+1,cnt2,cnt3);
	if(cnt2<n/2)
		get(i+1,now+a[i][2],cnt1,cnt2+1,cnt3);
	if(cnt3<n/2)
		get(i+1,now+a[i][3],cnt1,cnt2,cnt3+1);
	return;
}

bool cmp(fake a,fake b){
	return a.a1>b.a1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	
	while(t--){
		cin>>n;
		
		if(n>=1e5){
			for(int i=1;i<=n;i++){
				cin>>r[i].a1>>r[i].a2>>r[i].a3;
			}
			sort(r+1,r+n+1,cmp);
			int ans=0,cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(r[i].a1>=r[i].a2){
					if(cnt1<n/2){
						ans+=r[i].a1;
						cnt1++;
					}else ans+=r[i].a2;
				}else{
					if(cnt2<n/2){
						ans+=r[i].a2;
						cnt2++;
					}else ans+=r[i].a1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		
		if(n<=10){
			get(1,0,0,0,0);
			cout<<ans<<'\n';
			ans=-1;
			continue;
		}
		
		int max1=n/2;
		
		for(int i=1;i<=n;i++){
			int d=0;
			dp[i]=dp[i-1];
			for(int j=1;j<=3;j++){
				if(cnt[j]<max1){
					//dp[i]=max(dp[i-1],dp[i]);
					if(dp[i-1]+a[i][j]>dp[i]){
						dp[i]=dp[i-1]+a[i][j];
						d=j;
						//cnt[j]++;
						node tmp;
						tmp.dat=a[i][j];tmp.id=i;
						q[j].push(tmp);
					}
					//cout<<cnt[j]<<' ';
				}else{
					node t=q[j].top();
					int val=t.dat,id=t.id;
					if(a[i][j]<val)continue;
					//dp[i]=max(dp[i-1],dp[i]);
					int add,chose;
					if(j==1){
						if(a[id][2]>=a[id][3]){
							add=a[id][2];
							chose=2;
						}else{
							add=a[id][3];
							chose=3;
						}
						if(dp[i-1]+a[i][j]-val+add>dp[i]){
							dp[i]=dp[i-1]+a[i][j]-val+add;
							node tmp;
							tmp.dat=add;tmp.id=id;
							q[chose].push(tmp);
							cnt[chose]++;
						}
					}else if(j==2){
						if(a[id][1]>=a[id][3]){
							add=a[id][1];
							chose=1;
						}else{
							add=a[id][3];
							chose=3;
						}
						if(dp[i-1]+a[i][j]-val+add>dp[i]){
							dp[i]=dp[i-1]+a[i][j]-val+add;
							node tmp;
							tmp.dat=add;tmp.id=id;
							q[chose].push(tmp);
							cnt[chose]++;
						}
					}else{
						if(a[id][1]>=a[id][2]){
							add=a[id][1];
							chose=1;
						}else{
							add=a[id][2];
							chose=2;
						}
						if(dp[i-1]+a[i][j]-val+add>dp[i]){
							dp[i]=dp[i-1]+a[i][j]-val+add;
							node tmp;
							tmp.dat=add;tmp.id=id;
							q[chose].push(tmp);
							cnt[chose]++;
						}
					}
				}
			}
			if(d!=0)cnt[d]++;
			//cout<<dp[i]<<endl<<endl;
		}
		cout<<dp[n]<<'\n';
		memset(dp,0,sizeof(dp));
		clear();
	}

	return 0;
}
/*
1
4
4 0 0
3 0 0
5 0 0
3 0 0

*/
