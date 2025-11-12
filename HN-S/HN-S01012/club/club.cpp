#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=0,M=0;
int n,m,ans,suma,sumb,sumc,cnta,t,cntb,cntc,as,bs,cs,cnt,cnt2,dp[305][305][305],bo1,bo2;
int a[114514],b[114514],c[114514];
pair<LL,LL> p[114514];
bool cmp(pair<LL,LL> x,pair<LL,LL> y){
	return x.second-x.first>y.second-y.first;
}
bool cmp2(pair<LL,LL> x,pair<LL,LL> y){
	return x.second-x.first<y.second-y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);//*/
	
	cin>>t;
	while(t--){
		ans=0;
		memset(dp,0,sizeof dp);
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(c[i]!=0)bo2=1;
			if(b[i]!=0)bo1=1;
		}
		if(n<=600){
			for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					int l=i+j+k;
					if(i)dp[i][j][k]=max(dp[i-1][j][k]+a[l],dp[i][j][k]);
					if(j)dp[i][j][k]=max(dp[i][j-1][k]+b[l],dp[i][j][k]);
					if(k)dp[i][j][k]=max(dp[i][j][k-1]+c[l],dp[i][j][k]);
					if(l==n)ans=max(ans,dp[i][j][k]);
				}
			} 
		}
		}else if(bo1==0){
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<endl;
			continue;
		}else 
		if(bo2==0){
			int n2=n;
			for(int i=1;i<=n;i++){
				p[i]={a[i],b[i]};
				if(a[i]>b[i])cnt++;
			}
			
			
			if(cnt<n/2){
				for(int i=1;i<=n;i++){
					if(a[i]>b[i])ans+=a[i],n2--,p[i].second=-0x3f3f3f3f;
				}	
				sort(p+1,p+n+1,cmp);
			}
			
			else if(cnt>n/2){
				for(int i=1;i<=n;i++){
					if(a[i]<b[i])ans+=a[i],n2--,p[i].first=-0x3f3f3f3f;
				}	
			sort(p+1,p+n+1,cmp2);
			}
			
			else{
				for(int i=1;i<=n;i++)ans+=max(a[i],b[i]);
				cout<<ans<<endl;
				continue;
			}
			
			for(int i=1;i<=n/2;i++)ans+=(cnt<n/2?b[i]:a[i]);
			for(int i=n/2+1;i<=n2;i++)ans+=(cnt<n/2?a[i]:b[i]);
		}
		
		
		else{
			for(int i=1;i<=n;i++)ans+=max(a[i],max(b[i],c[i]));
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
