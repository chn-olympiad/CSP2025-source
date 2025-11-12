#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN][4];
int match[MAXN],n,T;
bool vis[MAXN];
vector<int> h[6];
struct node{
	int v,g,id;
};
bool cmp(node x,node y){
	return x.v>y.v;
}
vector<node> q1,q2; 
void solve(){
	//
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=3;i++){
		h[i].clear();
	}
	q1.clear();
	q2.clear();
	//
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
//			cout<<1<<endl;
			h[1].push_back(i);
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
//			cout<<2<<endl;
			h[2].push_back(i);
		}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
//			cout<<3<<endl;
			h[3].push_back(i);
		}
	}
//	cout<<"##\n";
	int p=1;
	while(p<=3&&h[p].size()<=n/2) p++;
	int ans=0;
	for(int i=1;i<=3;i++){
		for(auto k:h[i]){
			ans+=a[k][i];
		}
	}
//	cout<<"###\n";
	if(p>=4){
		cout<<ans<<endl;
		return;
	}
//	cout<<"####\n";
//	cout<<p<<endl;
	int res=h[p].size()-n/2;
	for(auto i:h[p]){
		if(p==1){
			int t1=a[i][2]-a[i][1],t2=a[i][3]-a[i][1];
			q1.push_back(node{t1,2,i});
			q2.push_back(node{t2,3,i});
		}else if(p==2){
			int t1=a[i][1]-a[i][2],t2=a[i][3]-a[i][2];
			q1.push_back(node{t1,1,i});
			q2.push_back(node{t2,3,i});
		}else{
			int t1=a[i][1]-a[i][3],t2=a[i][2]-a[i][3];
			q1.push_back(node{t1,1,i});
			q2.push_back(node{t2,2,i});
		}
	}
//	cout<<p<<endl;
	sort(q1.begin(),q1.end(),cmp);
	sort(q2.begin(),q2.end(),cmp);
//	cout<<p<<endl;
	int i=0,j=0;
//	cout<<res<<endl;
	while(res){
		if(i<q1.size()&&!vis[q1[i].id]&&q1[i].v>q2[j].v&&h[q1[i].g].size()<n/2){
			ans+=q1[i].v;
			vis[q1[i].id]=1;
			res--;
			i++;
			h[q1[i].g].push_back(q1[i].id);
		}else if(j<q2.size()&&!vis[q2[j].id]&&h[q2[j].g].size()<n/2){
			ans+=q2[j].v;
			vis[q2[j].id]=1;
			res--;
			j++;
			h[q2[j].g].push_back(q2[j].id);
		}else{
			if(h[q2[j].g].size()>=n/2) i++;
			if(h[q1[i].g].size()>=n/2) j++;
			if(vis[q1[i].id]) i++;
			if(vis[q2[j].id]) j++;
//			cout<<"#\n";
		}
	}
//	cout<<p<<endl;
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
//		cout<<"#\n";
		solve();
	}
	return 0;
} 
