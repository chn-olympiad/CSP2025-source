#include<bits/stdc++.h>
using namespace std;
struct people{
	int a[4],max,nxt;
}p[100010];
bool cmp(people x,people y){
	return x.a[x.max]>y.a[y.max];
}
int n;
priority_queue<pair<int,int> >q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			p[i].max=p[i].nxt=0;
			for(int j=1;j<=3;j++){
				cin>>p[i].a[j];
				if(p[i].a[j]>=p[i].a[p[i].max]){
					swap(p[i].max,p[i].nxt);
					p[i].max=j;
				}else if(p[i].a[j]>=p[i].a[p[i].nxt]){
					p[i].nxt=j;
				}
			}
		}sort(p+1,p+n+1,cmp);
		for(int i=1;i<=3;i++)
			while(!q[i].empty())q[i].pop();
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<i<<":"<<p[i].max<<" "<<p[i].nxt<<" "<<p[i].a[p[i].nxt]-p[i].a[p[i].max]<<"\n";
			ans+=p[i].a[p[i].max];
			q[p[i].max].push(make_pair(p[i].a[p[i].nxt]-p[i].a[p[i].max],i));
//			cout<<i<<"->"<<p[i].max<<" "<<q[p[i].max].size()<<"\n";
			if((int)q[p[i].max].size()>n/2){
				pair<int,int>k=q[p[i].max].top();
				q[p[i].max].pop();
				ans+=k.first;
				int x=k.second;
				q[p[x].nxt].push(make_pair(p[x].a[p[i].max]-p[x].a[p[x].nxt],i));
//				cout<<p[x].max<<"->"<<x<<"->"<<p[x].nxt<<"\n";
			}
		}cout<<ans<<"\n";
	}
	return 0;
}

