#include <bits/stdc++.h>

using namespace std;
long long t,n,b[100005],m[3],z;
pair<long long,long long> a[100005][3];
bool pmc(pair<long long,long long> x,pair<long long,long long> y){
	return x>y;
}
struct tni{
	long long x;
};
operator <(tni x,tni y){
	return ((a[x.x][b[x.x]].first-a[x.x][b[x.x]+1].first)==(a[y.x][b[y.x]].first-a[y.x][b[y.x]+1].first)?(a[x.x][b[x.x]].first-a[x.x][b[x.x]+2].first)>(a[y.x][b[y.x]].first-a[y.x][b[y.x]+2].first):(a[x.x][b[x.x]].first-a[x.x][b[x.x]+1].first)>(a[y.x][b[y.x]].first-a[y.x][b[y.x]+1].first));
}
priority_queue<tni> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			a[i][0].second=0;
			a[i][1].second=1;
			a[i][2].second=2;
			sort(a[i],a[i]+3,pmc);
			b[i]=0;
			q[a[i][0].second].push({i});
			m[a[i][0].second]++;
		}
		while(m[0]>n/2||m[1]>n/2||m[2]>n/2){
			for(int i=0;i<3;i++){
				if(m[i]>n/2){
//					cout<<i<<" "<<q[i].top().x<<" "<<a[q[i].top().x][b[q[i].top().x]+1].second<<endl;
					m[i]--;
					m[a[q[i].top().x][b[q[i].top().x]+1].second]++;
					b[q[i].top().x]++;
					q[a[q[i].top().x][b[q[i].top().x]+1].second].push(q[i].top());
					q[i].pop();
				}
			}
		}
		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" "<<a[i][b[i]].first<<endl;
			z+=a[i][b[i]].first;
		}
		cout<<z<<endl;
		for(int i=0;i<3;i++){
			while(!q[i].empty())q[i].pop();
			m[i]=0;
		}
		z=0;
	}
}
