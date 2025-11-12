#include<bits/stdc++.h>
using namespace std;
struct node{int a,b,c;};
void solve(){
	int n,cnt1=0,cnt2=0,cnt3=0,sum=0;cin>>n;
	vector<node> e(n+1);
	vector<int> d;
	for(int i=1,mx;i<=n;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
		mx=max({e[i].a,e[i].b,e[i].c});
		if(e[i].a==mx) sum+=e[i].a,cnt1++;
		else if(e[i].b==mx) sum+=e[i].b,cnt2++;
		else sum+=e[i].c,cnt3++;
	}
	int cnt=max({cnt1,cnt2,cnt3});
	if(cnt>n/2){
		for(int i=1,mx;i<=n;i++){
			mx=max({e[i].a,e[i].b,e[i].c});
			if(e[i].a==mx&&cnt1==cnt) d.push_back(e[i].a-max(e[i].b,e[i].c));
			else if(e[i].b==mx&&cnt2==cnt) d.push_back(e[i].b-max(e[i].a,e[i].c));
			else if(e[i].c==mx&&cnt3==cnt) d.push_back(e[i].c-max(e[i].a,e[i].b));
		}
		sort(d.begin(),d.end());
		for(int i=n/2+1,j=0;i<=cnt;j++,i++) sum-=d[j];
	}cout<<sum<<"\n";
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
/*
16min
*/
