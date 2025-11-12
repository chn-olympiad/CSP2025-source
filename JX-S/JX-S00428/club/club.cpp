#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define ull unsigned long long
//#define connect_or_leave_oi return
int T;
int n;
const int N=1e5+10;
//LL a[N][4];
struct node{
	LL maxx;int maxx_id;
	LL ma2;int ma2id;
	LL xc;
	friend bool operator<(node x,node y){
		return x.xc>y.xc;
	}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	// cout<<18961+16178+19722+17976+9953+10557+15344+13424+8769+16441;
	cin>>T;
	while(T--){
		vector<node>sz;
		cin>>n;
		for(int i=1;i<=n;i++){
			LL a,b,c;
			cin>>a>>b>>c;
			LL maxx=max(a,max(b,c));
			LL ma2;
			if(maxx==a){
				ma2=max(b,c);
				if(ma2==b)sz.push_back({maxx,1,ma2,2,maxx-ma2});
				else sz.push_back({maxx,1,ma2,3,maxx-ma2});
			}
			else if(maxx==b){
				ma2=max(a,c);
				if(ma2==a)sz.push_back({maxx,2,ma2,1,maxx-ma2});
				else sz.push_back({maxx,2,ma2,3,maxx-ma2});
			}
			else if(maxx==c){
				ma2=max(a,b);
				if(ma2==a)sz.push_back({maxx,3,ma2,1,maxx-ma2});
				else sz.push_back({maxx,3,ma2,2,maxx-ma2});
			}
		}
		sort(sz.begin(),sz.end());
		LL ans=0;
		int len=sz.size(),m=n/2;
		int cnt[4];
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=0;i<len;i++){
			if(cnt[sz[i].maxx_id]>=m){
				ans+=sz[i].ma2;
				cnt[sz[i].ma2id]++;
			}
			else{
				ans+=sz[i].maxx;
				cnt[sz[i].maxx_id]++;
			}
		}
		cout<<ans<<"\n";
	}
	//connect_or_leave_oi 0;
	return 0;
}
