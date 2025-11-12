#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int> >a[N];
pair<int,int>my_v[N];
void solve(){
//	cout<<"test\n";
	#define mkp make_pair
	#define fi first
	#define se second
	int n;
	cin>>n;
	vector<int>mycnt(5);
	for(int i=1;i<=n;i++){		
		cin>>a[i][0].fi>>a[i][1].fi>>a[i][2].fi;			
		a[i][0].se=1;
		a[i][1].se=2;
		a[i][2].se=3;
		
		sort(a[i].begin(),a[i].end());
		mycnt[a[i][2].se]++;
	}
	int top=0;
	for(int j=1;j<=3;j++){
		if(mycnt[j]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2].se!=j)	continue;
				my_v[++top]=mkp(a[i][2].fi-a[i][1].fi,i);	
			}
			sort(my_v+1,my_v+top+1);
			for(int i=1;i<=mycnt[j]-n/2;i++){
				swap(a[my_v[i].se][1],a[my_v[i].se][2]);
			}
			break;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][2].fi;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=N-3;i++){
		a[i].resize(3);
	}
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
} 
