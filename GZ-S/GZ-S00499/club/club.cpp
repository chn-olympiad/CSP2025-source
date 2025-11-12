//GZ-S00499 贵阳市第一中学 黄世杰
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long>pii;
const long long N=1e5+10;
long long n,vis[N];
priority_queue<long long,vector<long long>,greater<long long>>qa;
priority_queue<long long,vector<long long>,greater<long long>>qb;
priority_queue<long long,vector<long long>,greater<long long>>qc;
long long ans=0;
long long T;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			long long d1,d2,d3;
			scanf("%lld %lld %lld",&d1,&d2,&d3);
			if(d1>d2&&d1>d3){
				qa.push(d1-max(d2,d3));
				ans+=d1;
			}
			else if(d2>d1&&d2>d3){
				qb.push(d2-max(d1,d3));
				ans+=d2; 
			}
			else {
				qc.push(d3-max(d1,d2));
				ans+=d3;
			}
		}
		while(qa.size()>n/2){
			ans-=qa.top();
			qa.pop();
		}
		while(qb.size()>n/2){
			ans-=qb.top();
			qb.pop();
		}
		while(qc.size()>n/2){
			ans-=qc.top();
			qc.pop();
		}
		while(qa.size())qa.pop();
		while(qb.size())qb.pop();
		while(qc.size())qc.pop();
		cout<<ans<<endl;
	}
	return 0;
} 
