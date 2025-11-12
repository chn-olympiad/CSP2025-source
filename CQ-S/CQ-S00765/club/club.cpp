#include<bits/stdc++.h>
#define endl "\n"
//#define int long long
using namespace std;
int t,n,ans;
vector<int> v[4];
struct node{
	int id,x;
}a[200000][4];
bool cmp(node s1,node s2){
	return s1.x>s2.x;
}
bool cmp2(int s1,int s2){
	return (a[s1][1].x-a[s1][2].x)>(a[s2][1].x-a[s2][2].x);
}
void solve(int id){
	sort(v[id].begin(),v[id].end(),cmp2);
	for(int i=v[id].size()-1;i>=n/2;i--){		
		ans=ans+a[v[id][i]][2].x-a[v[id][i]][1].x;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		v[1].clear(),v[2].clear(),v[3].clear();
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][1].x>>a[i][2].x>>a[i][3].x,a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+1+3,cmp);
			v[a[i][1].id].push_back(i);
			ans+=a[i][1].x;
		}
		if(v[1].size()>(n/2)) solve(1);
		else if(v[2].size()>(n/2)) solve(2);
		else if(v[3].size()>(n/2)) solve(3);
		cout<<ans<<endl;
	}
	return 0;
}

