#include <bits/stdc++.h>

#define multicase() int t;cin>>t;while(t--)
#define ll long long
#define pii pair<ll,ll>
using namespace std;

const ll kMaxN = 1e5 + 7;

ll dp[kMaxN][7] , suf[kMaxN][7];

priority_queue<ll> que[kMaxN];

struct node{
	ll id , stu ,val;
	bool operator<(const node &a) const{
		return val > a.val;
	}
}thing[3*kMaxN];
ll tot;

//ll a[kMaxN] , b[kMaxN] , c[kMaxN];
ll n;


vector<ll> lststu[7];
ll stuHASH[7];
bitset<kMaxN> HASH;
ll ans;

priority_queue<ll> q[7];

ll num[kMaxN][7];

void init(){
	HASH.reset();
	memset(lststu , 0 , sizeof lststu);
	memset(stuHASH , 0 , sizeof stuHASH);
	for(int i = 1 ; i <= 3 ; i++){
		while(!q[i].empty()) q[i].pop();
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= 3 ; j++){
			num[i][j] = 0;
		}
	}
	tot = 0;
	ans = 0;
}

//ll dfs(ll pos , ll &id){
//	ll res = -1 , id = -1;				
//	ll lst = num[lststu[thing[i].id]][thing[i].id];
////			cout<<lst<<" ";
//	for(int k = 1 ; k <= 3 ; k++){
//		if(q[k].empty()) continue;
//		if(k == thing[i].id) continue;
//		if(HASH[k] + 1 > n/2) continue;
////				cout<<q[k].top()<<" ";
//		if(q[k].top() + thing[i].val > lst){
//			if(res < q[k].top() + thing[i].val){
//				res = q[k].top() + thing[i].val;
//				id = k;
//			}
//		}
//	}
//	return res;
//}

ll choic[kMaxN];

void solve(){
	init();
//	HASH.reset();
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
////		cin>>a[i]>>b[i]>>c[i];
		for(int j = 1 ; j <= 3 ; j++){
			thing[++tot].stu = i;
			thing[tot].id = j;
			cin>>thing[tot].val;
			num[i][j] = thing[tot].val;
		}
	}
	sort(thing + 1 , thing + 1 + tot);
	for(int i = 1 ; i <= tot ; i++){
		if(HASH[thing[i].stu]) continue;
		if(stuHASH[thing[i].id] + 1 <= n/2){
			choic[thing[i].stu] = thing[i].id;
//			cout<<"C"<<thing[i].stu<<" "<<thing[i].id<<"\n";
//			lststu[thing[i].id] = thing[i].stu;
			lststu[thing[i].id].push_back(thing[i].stu);
			HASH[thing[i].stu] = 1;
//			cout<<stuHASH[thing[i].id]<<"\n";
			stuHASH[thing[i].id]++;
			ans += thing[i].val;
			for(int k = 1 ; k <= 3 ; k++){
				if(k == thing[i].id) continue;
				q[k].push(num[thing[i].stu][k]);
			}
		}else{
//			cout<<lststu[thing[i].id].empty();
			ll res = -1 , id = -1;			
//			cout<<lststu[thing[i].id].empty();	
			ll lst = num[lststu[thing[i].id].back()][thing[i].id];
//			cout<<lst<<" ";
			for(int k = 1 ; k <= 3 ; k++){
				if(q[k].empty()) continue;
				if(k == thing[i].id) continue;
				if(HASH[k] + 1 > n/2) continue;
//				cout<<q[k].top()<<" ";
				if(q[k].top() + thing[i].val > lst){
					if(res < q[k].top() + thing[i].val){
						res = q[k].top() + thing[i].val;
						id = k;
					}
				}
			}
			if(res != -1){
				choic[lststu[thing[i].id].back()] = id;
				choic[thing[i].stu] = thing[i].id;
//				cout<<"A"<<lststu[thing[i].id].back()<<" "<<id<<" "<<thing[i].stu<<" "<<thing[i].id<<"\n";
				ans += res - lst;
				q[id].pop();
				HASH[thing[i].stu] = 1;
				lststu[thing[i].id].pop_back();
				lststu[thing[i].id].push_back(thing[i].stu);
				stuHASH[id]++;
			}
		}
	}
	ll sum = 0;
	for(int i = 1 ; i <= n ; i++){
//		cout<<choic[i]<<"\n";
		sum += num[i][choic[i]];
	}
	cout<<ans;
}

int main(){
	freopen("club.in" ,"r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	multicase(){
		solve();
		cout<<"\n";
	}
	return 0;
}

