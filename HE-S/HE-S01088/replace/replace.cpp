#include<bits/stdc++.h>
using namespace std;

const int M = 2e5+5 , N = 2.6e6;
int n , q;
string s1[M] , s2[M] , t1 , t2;

signed main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>n>>q;
	for(int i = 0; i < n; ++i) cin>>s1[i]>>s2[i];
	for(int i = 0; i < q; ++i){
		cin>>t1>>t2;
		int lt = t1.length() , ans = 0;
		for(int j = 0; j < n; ++j){
			int ls = s1[j].length();
			for(int k = 0; k <= lt - ls; ++k){
				if(t1.substr(0 , k) == t2.substr(0 , k)
				&& t1.substr(k , ls) == s1[j]
				&& t2.substr(k , ls) == s2[j]
				&& t1.substr(k + ls , lt - k - ls)
				== t2.substr(k + ls , lt - k - ls)) ++ans;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
// i hate string
// my ACAM is wrong at all
// there's no time for me to finish brute force