#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int T,n,ans=0;
priority_queue<pair<int,int> >q[4];
int num[5],mx[N],se[N],lo[N];
struct Person{
	int a[4];
}p[N];
void solve(){
	cin>>n;
	ans=0;
//	q[1].clear();q[2].clear();q[3].clear();
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	while(!q[3].empty())q[3].pop();
	for(int i=1;i<=n;i++){
		cin>>p[i].a[1]>>p[i].a[2]>>p[i].a[3];
	}
	for(int i=1;i<=n;i++){
		int Mx=max(p[i].a[1],max(p[i].a[2],p[i].a[3]));
		if(p[i].a[1]==Mx){
			mx[i]=1;
			se[i]=(p[i].a[2]>=p[i].a[3]?2:3);
			lo[i]=(p[i].a[2]<p[i].a[3]?2:3);
		}else if(p[i].a[2]==Mx){
			mx[i]=2;
			se[i]=(p[i].a[1]>=p[i].a[3]?1:3);
			lo[i]=(p[i].a[1]<p[i].a[3]?1:3);
		}else{
			mx[i]=3;
			se[i]=(p[i].a[1]>=p[i].a[2]?1:2);
			lo[i]=(p[i].a[1]<p[i].a[2]?1:2);
		}
	}
	for(int i=1;i<=n;i++){
		q[mx[i]].push(make_pair(p[i].a[se[i]]-p[i].a[mx[i]],i));
		ans+=p[i].a[mx[i]];
		if(q[mx[i]].size()>n/2){
			pair<int,int> v=q[mx[i]].top();
			ans+=v.first;
			q[mx[i]].pop();
			q[se[v.second]].push(make_pair(p[i].a[lo[v.second]]-p[i].a[se[v.second]],v.second));
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
