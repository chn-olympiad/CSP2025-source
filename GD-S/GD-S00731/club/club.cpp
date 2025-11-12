#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct Stu{
	int club,sat,id;
	bool operator<(const Stu &o)const{
		return sat>o.sat;
		return club<o.club;
		return id<o.id;
	}
};


int visc[3];
int visp[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<Stu>q;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			q.push_back({1,a1,i});
		}
		sort(q.begin(),q.end());
		int cnt=0;
		int ans=0;
		for(int i=0;i<=q.size()-1;i++){
			if(cnt>=n/2)break;
			ans+=q[i].sat;
			cnt++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
