#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int t,ans,n,pos,all,a[100010][3];
struct node{
	int num,val;
}cnt[3];
vector<int> v[3];
bool cmp(node t1,node t2){
	return t1.val>t2.val;
}
bool cmp0(int t1,int t2){
	return (max(a[t1][1],a[t1][2])-a[t1][0])>(max(a[t2][1],a[t2][2])-a[t2][0]);
}
bool cmp1(int t1,int t2){
	return (max(a[t1][0],a[t1][2])-a[t1][1])>(max(a[t2][0],a[t2][2])-a[t2][1]);
}
bool cmp2(int t1,int t2){
	return (max(a[t1][1],a[t1][0])-a[t1][2])>(max(a[t2][1],a[t2][0])-a[t2][2]);
}
void solve(){
	cin>>n;
	cnt[0].num=0,cnt[1].num=1,cnt[2].num=2;
	cnt[0].val=cnt[1].val=cnt[2].val=0;
	v[0].clear();v[1].clear();v[2].clear();
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	ans=0,all=0;
	for(int i=1;i<=n;i++){
		pos=0;
		if(a[i][pos]<a[i][1]||a[i][pos]==a[i][1]) pos=1;
		if(a[i][pos]<a[i][2]||a[i][pos]==a[i][2]) pos=2;
		for(int j=0;j<=2;j++){
			if(a[i][pos]==a[i][j]){
				cnt[j].val++;
				v[j].push_back(i);
			}
		}
		ans+=a[i][pos];
	}
	sort(cnt,cnt+3,cmp);
//	cout<<cnt[0].val<<" "<<cnt[1].val<<" "<<cnt[2].val<<"\n";
	if(cnt[0].val>n/2){
		if(cnt[0].num==0){
//			cout<<"0:";
			sort(v[0].begin(),v[0].end(),cmp0);
			all=v[0].size();
			for(int i=0;i<v[0].size();i++){
				ans=ans+max(a[v[0][i]][1],a[v[0][i]][2])-a[v[0][i]][0];
				all--;
				if(all<=n/2){
					cout<<ans<<"\n";
					return ;
				}
			}
		}
		else if(cnt[0].num==1){
//			cout<<"1:";
			sort(v[1].begin(),v[1].end(),cmp1);
			all=v[1].size();
			for(int i=0;i<v[1].size();i++){
				ans=ans+max(a[v[1][i]][0],a[v[1][i]][2])-a[v[1][i]][1];
				all--;
				if(all<=n/2){
					cout<<ans<<"\n";
					return ;
				}
			}
		}
		else{
//			cout<<"2:"/*;*/
			sort(v[2].begin(),v[2].end(),cmp2);
			all=v[2].size();
			for(int i=0;i<v[2].size();i++){
//				cout<<max(a[v[2][i]][1],a[v[2][i]][0])-a[v[2][i]][2]<<"\n";
				ans=ans+max(a[v[2][i]][1],a[v[2][i]][0])-a[v[2][i]][2];
				all--;
				if(all<=n/2){
					cout<<ans<<"\n";
					return ;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) solve();
	return 0;
}
