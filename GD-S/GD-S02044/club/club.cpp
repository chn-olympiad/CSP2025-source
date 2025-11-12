#include<bits/stdc++.h>
using namespace std;
long long t,n,px[100005],ans,sz[4],nr;
pair<long long,long long>pr[100005][4];
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q[4]; 
void find(long long x){
	int v=px[x],d=pr[x][v].second;
	ans-=pr[x][v].first;
	px[x]--;
	q[d].push({pr[x][px[x]].first,x});
	sz[d]++;
	if(sz[d]>nr){
		pair<long long,long long>o=q[d].top();
		q[d].pop();
		sz[d]--;
		find(o.second);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t--;){
		ans=0;
		cin>>n;
		sz[1]=sz[2]=sz[3]=0;
		nr=n/2;
		for(int i=1;i<=3;i++)
		for(;!q[i].empty();){
			q[i].pop();
		}
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&pr[i][1].first,&pr[i][2].first,&pr[i][3].first);
			pr[i][1].second=1,pr[i][2].second=2,pr[i][3].second=3;
			sort(pr[i]+1,pr[i]+1+3);
			ans+=max(max(pr[i][1].first,pr[i][2].first),pr[i][3].first);
			pr[i][1].first=pr[i][2].first-pr[i][1].first;
			pr[i][2].first=pr[i][3].first-pr[i][2].first;
			pr[i][3].first=0;
			px[i]=3;
		}
		for(int i=1;i<=n;i++){
			find(i);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

