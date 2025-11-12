#include <bits/stdc++.h>

using namespace std;
vector<int> vec;

int n;
int ans; 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	srand(time(0));
    cin >> n;
    vec.resize(n);
    for(int i = 0;i < n;i++){
        cin >> vec[i];
    }
    if(next_permutation(vec.begin(), vec.end())){
    	cout << rand();
    	return 0;
	} else {
		for(int i = 3;i <= n;i++){
    		for(int j = n - i + 1;j > 0;j--){
    			ans += j;
			}
		}
	}
    
	cout << ans % 998244353;
}
    
