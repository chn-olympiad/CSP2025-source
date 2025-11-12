#include<bits/stdc++.h>
#define int long long
using namespace std;
struct fish{
	int best;
	int nxt;
	int op;
}a[100005];
struct qwq{
	int x,id;
};
bool cmpqwq(qwq x,qwq y){
	return x.x>y.x;
}
bool cmpfish(fish x,fish y){
	return x.nxt<y.nxt;
}
bool cmpvec(vector<fish>x,vector<fish>y){
	return x.size()>y.size();
}
void solve(){
	int n;
	cin>>n;
	int ans=0;
	vector<fish>ve[3];
	for(int i=1;i<=n;i++){
		qwq flc[3];
		for(int j=0;j<3;j++)
		cin>>flc[j].x,flc[j].id=j;
		sort(flc,flc+3,cmpqwq);
		a[i].best=flc[0].x;
		a[i].op=flc[0].id;
		a[i].nxt=flc[0].x-flc[1].x;
		ve[a[i].op].push_back(a[i]);
		ans+=a[i].best;
	}
	sort(ve,ve+3,cmpvec);
	sort(ve[0].begin(),ve[0].end(),cmpfish);
//	cout<<ans<<' ';
	for(int i=0;i<((int)(ve[0].size()))-n/2;i++)
	ans-=ve[0][i].nxt;//,cout<<ve[0][i].nxt<<"! ";
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}
/*
da yang li kan cuo le
xu kong tiao shi 15min

14:53 ACed.
*/
