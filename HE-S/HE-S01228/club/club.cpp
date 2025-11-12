#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m,t;
struct cl{
	int id,x;
}a[N][5];
struct node{
	int x,y,id1,id2;
	bool operator <(const node &p) const{
		return x-y>p.x-p.y;
	}
};
bool cmp(cl x,cl y){
	return x.x>y.x;
}
multiset<node> s1;
int vi[10];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			cin>>a[i][j].x;
			a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+1+3,cmp);
			s1.insert({a[i][1].x,a[i][2].x,a[i][1].id,a[i][2].id});
		}
		int ans=0;
		while(s1.size()){
			auto k=*s1.begin();
			if(vi[k.id1]<n/2){
				vi[k.id1]++;
				ans+=k.x;
			}
			else{
				vi[k.id2]++;
				ans+=k.y;
			}
			s1.erase(s1.begin());
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			a[i][1].x=a[i][1].id=a[i][2].x=a[i][2].id=a[i][3].x=a[i][3].id=0;
		}
		for(int i=1;i<=3;i++)vi[i]=0;
	}
	return 0;
}
