#include <bits/stdc++.h>
using namespace std;

#define int long long
#define db double
#define pii pair<long long, long long>
#define endl "\n"

const int MXN = 5e5+10;

struct node{
	int ins, val;
	
	const bool operator<(node oth)const{
        return (val == oth.val)?(ins < oth.ins):(val < oth.val);
	}
};
struct slin{
	int l, r;
	
	const bool operator<(slin oth)const{
        return (l == oth.l)?(r > oth.r):(l < oth.l);
	}
};

int n,k, ans = 0;
int a[MXN], sum[MXN], xsum[MXN], dp[MXN];
node stsum[MXN], stxor[MXN];
vector<slin> slins;

signed main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	   
	ios::sync_with_stdio(0);
	cin.tie(0);
	   
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	sum[i] = sum[i-1] ^ a[i];
    	xsum[i] = sum[i]^k;
    	stsum[i] = {i,sum[i]};
    	stxor[i] = {i,xsum[i]};
	}
    
    sort(stsum+1, stsum+n+1);
    sort(stxor+1, stxor+n+1);
    
    for(int i = 1; i < n; i++){
    	for(int j = i+1; j <= n; j++){
    		if(sum[i] == xsum[j]){
    			slins.push_back({i+1,j});
			}
		}
	}
	
	sort(slins.begin(),slins.end());
	
	int i = 1;
	for(slin s: slins){
		//	 		   				 		 		cout << s.l << ' ' << s.r << endl;
		if(s.l >= s.r)continue;
		if(s.l <= i)continue;
		else{
			ans++;
			i = s.r;
		}
	}
	
	cout << 2*ans;
	   
	return 0;
}

