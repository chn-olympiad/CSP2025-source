#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z;
struct man {
	int now,idx;//id for set cant same
	int alg[4][3];//a,a.bu,b,b.bu,c,c.bu
	const operator < (const man &yo) {
		return alg[now][1]-alg[now+1][1]<yo.alg[yo.now][1]-yo.alg[yo.now+1][1];
	}

};
operator < (const man& a, const man& b) {
	return a.alg[a.now][1]-a.alg[a.now+1][1]<b.alg[b.now][1]-b.alg[b.now+1][1];
}
man a[100005];
multiset<man> mp[4];
int ans=0;
void try_join(man u) {
	int will=u.alg[1][2];
	if(mp[will].size()<(n/2)) {
		u.now=1;
		mp[will].insert(u);
		ans+=u.alg[1][1];
		//cout<<"man "<<u.idx<<" is join in "<<will<<"! ans is more "<<u.alg[1][1]<<"\n";
	} else {
		man v=*mp[will].begin();
		if(u.alg[1][1]+v.alg[v.now+1][1]>u.alg[2][1]+v.alg[v.now][1]) {
			mp[will].erase(mp[will].begin());
			ans-=v.alg[v.now][1];
			//cout<<"man "<<v.idx<<" be changen ! ans is less "<<v.alg[v.now][2]<<"\n";
			v.now++;
			//cout<<"man "<<v.idx<<" be changen in"<<v.alg[v.now][2]<<" ans is more "<<v.alg[v.now][1]<<"\n";
			ans+=v.alg[v.now][1];
			mp[v.alg[v.now][2]].insert(v);
			u.now=1;
			mp[will].insert(u);
			ans+=u.alg[1][1];
			//cout<<"man "<<u.idx<<" is join in "<<will<<"! ans is more "<<u.alg[1][1]<<"\n";
		} else {
			u.now=2;
			mp[u.alg[2][2]].insert(u);
			ans+=u.alg[2][1];
			//cout<<"man "<<u.idx<<" to join in "<<u.alg[2][2]<<"! ans is more "<<u.alg[2][1]<<"\n";
		}
	}
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	//cout<<t<<"\n";
	while(t--) {
		cin>>n;
		ans=0;
		mp[1].clear();
		mp[2].clear();
		mp[3].clear();
		
		for(int i=1; i<=n; i++) {
			int mom[4]={};
			cin>>mom[1]>>mom[2]>>mom[3];
			//cout<<mom[1]<<" "<<mom[2]<<" "<<mom[3]<<"\n";
			a[i].idx=i;
			a[i].now=1;
			for(int j=1; j<=3; j++) {
				int maxn=0;
				mom[0]=-1145;
				for(int k=1; k<=3; k++) {
					if(mom[k]>=mom[maxn])maxn=k;
				}
				a[i].alg[j][2]=maxn;
				a[i].alg[j][1]=mom[maxn];
				a[i].alg[j][0]=0;
				mom[maxn]=-1145;
			}
			//cout<<a[i].alg[1][1]<<" "<<a[i].alg[2][1]<<" "<<a[i].alg[3][1]<<"\n";
			
		}
		for(int i=1; i<=n; i++) {
			try_join(a[i]);//cout<<mp[1].size()<<mp[2].size()<<mp[3].size()<<"\n";
		}
		
		cout<<ans<<"\n";
	}
	//system("fc club.out club5.ans");
	return 0;
}
/*i think is fanhui tanxin 14:37
oh no 15:13
yes! 16:20
i am juruo
but so many dates;
I will checking my code in 5minute;16:21
i wrong.my sort is wrong.now is good;17:00
*/
