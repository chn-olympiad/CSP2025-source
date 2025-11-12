#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,inf=1e9+10;
int t,n;
int a[4][N];
//struct node{
//	int num;
//	int d[4];
//}a[N];
//pair<int,pair<int,int> >minx[4],minx1[4];
//vector<pair<int,int> >vec[4];
//void solve(int i,int j,int limit){
//	int k=0,l=0;
//	if(j==1)k=2,l=3;
//	if(j==2)k=1,l=3;
//	if(j==3)k=1,l=2;
//	int seb=0,sea=0;
//	if(minx[j].first!=inf){
//		if(a[minx[j].second.first].d[k]>=a[minx[j].second.first].d[l]){
//			seb=k;
//		}
//		else seb=l;
//	}
//	if(a[i].d[k]>=a[i].d[l]){
//		sea=k;
//	}
//	else sea=l;
//	
//	if(vec[j].size()<limit){
//		vec[j].push_back({a[i].d[j],a[i].num});
//		if(minx[j].first>=a[i].d[j]){
//			minx1[j]=minx[j];
//			minx[j]={a[i].d[j],{a[i].num,vec[j].size()}};
//		}
//		else if(minx1[j].first>=a[i].d[j]){
//			minx1[j]={a[i].d[j],{a[i].num,vec[j].size()}};
//		}
//		return 0;
//	}
//	else if(a[i].d[j]+a[minx[j].second.first].d[seb]-minx[j].first>=a[i].d[sea]){
//		vec[j][minx[j].second.second]={a[i].d[j],{a[i].num,minx[j].second.second}};
//		if(minx1[j].first>=a[i].d[j]){
//			minx1[j]={a[i].d[j],{a[i].num,vec[j].size()}};
//		}
//	}
//}
int solve(int dep,int s1,int s2,int s3){
	if(dep==n+1)return 0;
	int ans=0,ans1=0,ans2=0,ans3=0;
		if(s1<n/2){
			ans1=max(ans1,ans1+a[1][dep]+solve(dep+1,s1+1,s2,s3));
//			cout<<ans1<<'\n';
		}
		if(s2<n/2){
			ans2=max(ans2,ans2+a[2][dep]+solve(dep+1,s1,s2+1,s3));
//			cout<<ans2<<'\n';
		}
		if(s3<n/2){
			ans3=max(ans3,ans3+a[3][dep]+solve(dep+1,s1,s2,s3+1));
//			cout<<ans3<<'\n';
		}
	ans=max(ans1,max(ans2,ans3));
	return ans;
}
bool cmp(int a1,int a2){
	return a1>a2;
}
void solve1(){
	sort(a[1]+1,a[1]+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[1][i];
	}
	cout<<ans<<'\n';
		
}
void solve2(){
	int f[N][N];
	for(int i=1;i<=n;i++){
		f[0][i]=max(f[0][i-1],f[0][i-1]+a[2][i]);
		f[i][0]=max(f[i-1][0],f[i-1][0]+a[1][i]);
		for(int j=1;j<i;j++){
			f[j][i-j]=max(f[j-1][i-j]+a[1][i],f[j][i-j-1]+a[2][i]);
		}
	}
	cout<<f[n/2][n/2]<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int lim=n/2;
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i],sum1+=a[1][i],sum2+=a[2][i],sum3+=a[3][i];
		if(n<=10)cout<<solve(1,0,0,0)<<'\n';
		else if(sum2+sum3==0)solve1();
		else if(sum3==0)solve2();
		else cout<<0<<'\n';
//		minx[1]={inf,inf},minx[2]={inf,inf},minx[3]={inf,inf};
//		minx1[1]={inf,inf},minx1[2]={inf,inf},minx1[3]={inf,inf};		
//		memset(a,0,sizeof a);
//		for(int i=1;i<=3;i++)vec[i].clear();
//		for(int i=1;i<=n;i++){
//			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3]>>a[i].num;
//			int maxx=max(a[i].d[1],max(a[i].d[2],a[i].d[3]));
////			if(a[i].d[1]==maxx){
////				if(vec[1].size()<lim){
////					vec[1].push_back({d1,a[i].num});
////					if(min1.first>=d1){
////						min1={d1,a[i].num};
////					}
////					continue;
////				}
////				else if(vec[1].){
////					if(d2>=d3){
////						
////					}
////				}
////			}
////		}
		
		
	}
	return 0;
}

