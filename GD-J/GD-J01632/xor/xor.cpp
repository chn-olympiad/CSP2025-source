#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxnum=(1<<20)+5;
int n , k , A[500004];
vector<int> vec[maxnum];
vector<pair<int,int>> V;
bool vis[maxnum];
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first){
		return x.second<y.second;
	}
	return x.first<y.first;
}
int dp[500004];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int cnt=0;
	for(int i=1;i <= n;i++){
		scanf("%d",&A[i]);
		cnt^=A[i];
		vec[cnt].push_back(i);
	}
	for(int i=0;i < (1<<20);i++){
		if(vis[i])continue;
		vis[i]=1;
		int j=i^k , p=0 , q=0;
		vis[j]=1;
		while(p<vec[i].size()&&q<vec[j].size()){
			if(vec[i][p]<vec[j][q]){
				V.push_back({vec[i][p]+1,vec[j][q]});
				p++;
			}else{
				V.push_back({vec[j][q]+1,vec[i][p]});
				q++;
			}
		}
	}
	int sz=V.size() , ans=0;
	sort(V.begin(),V.end(),cmp);
	for(int i=0;i < sz;i++)dp[i]=1;
	for(int i=0;i < sz;i++){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(V[mid].second>=V[i].first){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		if(l>=i)continue;
		dp[i]+=dp[l];
	}
	for(int i=0;i < sz;i++)ans=( (ans<dp[i]) ?dp[i]:ans);
	printf("%d",ans);
	return 0;
}
