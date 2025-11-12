#include <bits/stdc++.h>

#define fst first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using p_q = priority_queue<pair<ll,pair<int,int> > >;

const int N = 1e5+50;
const ll inf = 1e18;

ll a[N][4];
int b[N][4];
ll c[N];
int tms[4];

int mian(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			b[i][0]=0;
			if(a[i][1]>=a[i][2]){
				b[i][1]=1,b[i][2]=2;
			} else {
				b[i][1]=2,b[i][2]=1;
			}
		}
		else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0]){
			b[i][0]=1;
			if(a[i][2]>=a[i][0]){
				b[i][1]=2,b[i][2]=0;
			} else {
				b[i][1]=0,b[i][2]=2;
			}
		} else{
			b[i][0]=2;
			if(a[i][1]>=a[i][0]){
				b[i][1]=1,b[i][2]=0;
			} else {
				b[i][1]=0,b[i][2]=1;
			}
		}
		tms[b[i][0]]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][b[i][0]];
	}
	if(tms[0]<=n/2&&tms[1]<=n/2&&tms[2]<=n/2){
		cout<<ans<<endl;
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(tms[b[i][0]]>n/2)
				c[++cnt]=a[i][b[i][0]]-a[i][b[i][1]];
		}
		sort(c+1,c+1+cnt);
		for(int i=n/2+1;i<=cnt;i++){
			ans-=c[cnt-i+1];
		}
		cout<<ans<<endl;
	}
	tms[0]=tms[1]=tms[2]=0;
	for(int i=1;i<=n;i++){
		a[i][0]=a[i][1]=a[i][2]=0;
		b[i][0]=b[i][1]=b[i][2]=0;
		c[i]=0;
	}
	
	return 0;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	cin>>_;
	while(_-->0){
		mian();
	}
	
	return 0;
}

