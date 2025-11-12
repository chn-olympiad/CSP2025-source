#include <bits/stdc++.h>
using namespace std;

#define int long long
#define db double
#define pii pair<long long, long long>
#define endl "\n"

const int MXN = 5010, MOD = 998244353;

int n,a[MXN],f[MXN];

void solve1(){
	vector<int> tmp;
	int sum,k,ans=0;
	bool flag = 1;
	for(int i = 1; i <= (1 << (n+1)); i++){
		tmp.assign(n,0);
		sum = 0, k = 1;
		
		for(int j = 1; j <= n; j++){
				  	   	 	   		   				//cout << (i&(1<<j)) << ' ';
			if(i&(1<<j)){
				tmp[k++] = a[j];
			}
		}
		for(int j = 1; j < k; j++){
			sum += tmp[j];
		}
		if(k-1 >= 3 && 2*tmp[k-1] < sum && flag)ans++;
		flag = !flag; 
		ans %= MOD;
			   	   	   			  			  			 			 	//cout << ans << endl;
	}
	cout << ans;
}

void solve2(){
	int ans = 1;
	for(int i = 1; i <= n; i++){
		ans = ans*2%MOD;
	}
	ans = (ans+MOD-n*(n+1)/2);
	cout << ans;
}


signed main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	   
	ios::sync_with_stdio(0);
	cin.tie(0);
	   
    cin >> n; 
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	if(n <= 20)solve1();
	else solve2();
	   
	return 0;
 }

