#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m[100005][4],ans,cnt[3],mxi;
struct H{
	ll num,xb;
	bool operator <(const H &a)const{
		return num<a.num;
	}
}cd[3][100005];
bool ca[100005];
void solve(){
	cin>>n;
	ans=0;
	cnt[0]=0;
	cnt[1]=0;
	cnt[2]=0;
	for(int i=1;i<=n;i++){
		cin>>m[i][0]>>m[i][1]>>m[i][2];
		ca[i]=0;
		if(m[i][0]>=m[i][1]&&m[i][0]>=m[i][2]){
			mxi=0;
		}else if(m[i][1]>=m[i][0]&&m[i][1]>=m[i][2]){
			mxi=1;
		}else{
			mxi=2;
		}
		ans+=m[i][mxi];
		m[i][3]=mxi;
		cnt[mxi]++;
		cd[0][i].num=m[i][mxi]-m[i][0];
		cd[1][i].num=m[i][mxi]-m[i][1];
		cd[2][i].num=m[i][mxi]-m[i][2];
		cd[0][i].xb=i;
		cd[1][i].xb=i;
		cd[2][i].xb=i;
		cd[mxi][i].num=0x3f3f3f3f3f3f3f3f;
	}
	ll cag=-1;
	if(cnt[0]>n/2){
		cag=0;
	}else if(cnt[1]>n/2){
		cag=1;
	}else if(cnt[2]>n/2){
		cag=2;
	}
	if(cag==-1){
		cout<<ans<<"\n";
		return ;
	}
	ll a=(cag+1)%3;
	ll b=(cag+2)%3;
	sort(cd[a]+1,cd[a]+1+n);
	sort(cd[b]+1,cd[b]+1+n);
	ll ai=1;
	ll bi=1;
	while(cnt[cag]>n/2){
		if(ca[cd[a][ai].xb]==1){
			ai++;
			continue;
		}else if(ca[cd[b][bi].xb]==1){
			bi++;
			continue;
		}
		if(cd[a][ai].num<cd[b][bi].num){
			ans-=cd[a][ai].num;
			ca[cd[a][ai].xb]=1;
			ai++;
			cnt[cag]--;
		}else{
			ans-=cd[b][bi].num;
			ca[cd[b][bi].xb]=1;
			bi++;
			cnt[cag]--;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}