#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct node{
    long long  d1,d2,d3,mai,mid,mii,maxn;
}d[100005],dp[100005];
long long fc(long long a,long long b,long long c){
	double p=(a*1.0+b*1.0+c*1.0)/3;
	return (a-p)*(a-p)+(b-p)*(b-p)+(c-p)*(c-p);
}
bool cmp(node x,node y){
	x.maxn=max(x.d1,x.d2);
	x.maxn=max(x.d3,x.maxn);
	y.maxn=max(y.d1,y.d2);
	y.maxn=max(y.d3,y.maxn);
	if(x.maxn!=y.maxn) return x.maxn>y.maxn;
	return fc(x.d1,x.d2,x.d3)<fc(y.d1,y.d2,y.d3);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].d1>>d[i].d2>>d[i].d3;
			if(d[i].d1>d[i].d2){
				if(d[i].d1>d[i].d3){
					d[i].mai=1;
					if(d[i].d2>d[i].d3) d[i].mid=2,d[i].mii=3;
				}
				else d[i].mai=3,d[i].mid=1,d[i].mii=2;
			}
			else {
				if(d[i].d2>d[i].d3){
					d[i].mai=2;
					if(d[i].d1>d[i].d3) d[i].mid=1,d[i].mii=3;
				}
				else d[i].mai=3,d[i].mid=2,d[i].mii=1;
			}//计算每一项最大值、最小值、中间值的id
		}
		sort(d+1,d+n+1,cmp);
		dp[1].d1=d[1].d1,dp[1].d2=d[1].d2,dp[1].d3=d[1].d3;//初始化
		dp[1].maxn=max(dp[1].d1,dp[1].d2);
		dp[1].maxn=max(dp[1].d3,dp[1].maxn);//求每组最大值
		dp[1].mai=1,dp[1].mid=1,dp[1].mii=1;//dp数组的mai、mid、mii相当于d1d2d3的个数
		int cnt=n/2;
		for(int i=2;i<=n;i++){
			dp[i].mai=dp[i-1].mai;
			dp[i].mid=dp[i-1].mid;
			dp[i].mii=dp[i-1].mii;
			if(dp[i].mai+1<=cnt) dp[i].d1=max(dp[i-1].maxn+d[i].d1,dp[i-1].d1),dp[i].mai++;
			else if(dp[i].mai<=cnt){
				dp[i].d1=max(dp[i-1].d2,dp[i-1].d3)+d[i].d1;
				if(dp[i].d1>dp[i-1].d1){
					//if(dp[i-1].d2>dp[i-1].d3) dp[i].mid++;
					//else dp[i].mii++;
				}else dp[i].d1=dp[i-1].d1,dp[i].mai++;
			}
			if(dp[i].mid+1<=cnt) dp[i].d2=max(dp[i-1].maxn+d[i].d2,dp[i-1].d2),dp[i].mid++;
			else if(dp[i].mid<=cnt){
				dp[i].d2=max(dp[i-1].d1,dp[i-1].d3)+d[i].d2;
				if(dp[i].d2>dp[i-1].d2){
					//if(dp[i-1].d1>dp[i-1].d3) dp[i].mai++;
					//else dp[i].mii++;
				}else dp[i].d2=dp[i-1].d2,dp[i].mid++;
			}	
			if(dp[i].mii+1<=cnt) dp[i].d3=max(dp[i-1].maxn+d[i].d3,dp[i-1].d3),dp[i].mii++;
			else if(dp[i].mii<=cnt){
				dp[i].d3=max(dp[i-1].d1,dp[i-1].d2)+d[i].d3;
				if(dp[i].d3>dp[i-1].d3){
					//if(dp[i-1].d1>dp[i-1].d2) dp[i].mai++;
					//else dp[i].mid++;
				}else dp[i].d3=dp[i-1].d3,dp[i].mii++;
			}
			dp[i].maxn=max(dp[i].d1,dp[i].d2);
			dp[i].maxn=max(dp[i].maxn,dp[i].d3);
			dp[i].maxn=max(dp[i].maxn,dp[i-1].maxn);
			//for(int j=1;j<=i;j++) cout<<dp[j].d1<<" "<<dp[j].d2<<" "<<dp[j].d3<<endl;
		}
		cout<<dp[n].maxn<<endl;
	}
    return 0;
}
