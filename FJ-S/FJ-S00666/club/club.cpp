#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=0x3f3f3f3f;
int T,n,mov[100010][10],to[100010][10],cnt[10];
struct node{
	int id,v;
	bool operator <(node x){
		return v>x.v;
	}
}s[100010][10];
struct nodee{
	int id,add,v;
};
bool operator <(const nodee x,const nodee y){
	return x.v>y.v;
}
priority_queue<node,vector<nodee> > q[10];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int o=1;o<=T;o++){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;cin>>s[i][j].v,s[i][j].id=j,j++);
			sort(s[i]+1,s[i]+4);
			for(int j=1;j<3;mov[i][s[i][j].id]=s[i][j].v-s[i][j+1].v,to[i][s[i][j].id]=s[i][j+1].id,j++);
			mov[i][s[i][3].id]=MAX;
			cnt[s[i][1].id]++;
			ans+=s[i][1].v;
			q[s[i][1].id].push((nodee){i,s[i][1].id,mov[i][s[i][1].id]});
			if(cnt[s[i][1].id]>(n/2)){
				nodee qq=q[s[i][1].id].top();
				q[s[i][1].id].pop();
				ans-=qq.v;
				cnt[s[i][1].id]--;
				q[to[qq.id][qq.add]].push((nodee){qq.id,to[qq.id][qq.add],mov[qq.id][qq.add]});
				cnt[to[qq.id][qq.add]]++;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=3;cnt[i]=0,i++)
			for(;q[i].size();q[i].pop());
	}
	return 0;
} 

