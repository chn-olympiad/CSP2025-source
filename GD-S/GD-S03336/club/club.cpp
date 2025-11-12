#include<bits/stdc++.h>
#define int long long
using namespace std;
#define l first
#define r second
const int maxn=1e5+5;
int n,len,ans,cnt[5];
struct node{
	int val,pos;
}s[maxn][5];
pair<pair<pair<int,int>,int>,pair<int,int>> p[maxn];
bool cmp(node A,node B){
	if(A.val==B.val) return A.pos>B.pos;
	return A.val>B.val;
}
priority_queue<pair<pair<pair<int,int>,int>,pair<int,int> >,vector<pair<pair<pair<int,int>,int>,pair<int,int> > >,greater<pair<pair<pair<int,int>,int>,pair<int,int> > > >q;
void solve(){
	while(q.size()!=0){
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) break;
		if(cnt[q.top().r.l]<=n/2){
			q.pop();
			continue;
		}
		cnt[q.top().r.l]--;
		cnt[q.top().r.r]++;
		ans-=q.top().l.l.l;
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) break;
		if(q.top().l.r==1){
			int po=q.top().l.l.r;
			q.pop();
			q.push({{{s[po][2].val-s[po][3].val,po},2},{s[po][2].pos,s[po][3].pos}});
			continue;
		}
		q.pop();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		len=0;
		while(q.size()!=0) q.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j].val;
				s[i][j].pos=j;
			}
			sort(s[i]+1,s[i]+4,cmp);
			ans+=s[i][1].val;
			cnt[s[i][1].pos]++;
			p[++len]={{{s[i][1].val-s[i][2].val,i},1},{s[i][1].pos,s[i][2].pos}};
			q.push(p[len]);
		}
		solve();
		cout<<ans<<endl;
	}
	return 0;
} 
