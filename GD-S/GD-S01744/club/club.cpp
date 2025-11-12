#include<bits/stdc++.h>
using namespace std;
const int N=1e5; 
int n;
struct stu{
	int t,s;
}x[N+5];
bool operator<(stu a,stu b){
	return a.s<b.s;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		int s[3]={0,0,0};
		for(int i=1;i<=n;++i){
			pair<int,int> a[3];
			cin>>a[0].first>>a[1].first>>a[2].first; 
			a[0].second=0,a[1].second=1,a[2].second=2;
			sort(a,a+3,greater<pair<int,int>>()); 
			x[i]={a[0].second,a[0].first-a[1].first};
			s[a[0].second]++,ans+=a[0].first;
		}
		int t=-1;
		if(s[0]>n/2) t=0;
		if(s[1]>n/2) t=1;
		if(s[2]>n/2) t=2;
		if(t!=-1){
			sort(x+1,x+1+n);
			for(int i=1;i<=n&&s[t]>n/2;++i) if(x[i].t==t){
				s[t]--;ans-=x[i].s;
			}
		}
		cout<<ans<<'\n';
	}
}
