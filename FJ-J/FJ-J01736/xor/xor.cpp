#include<bits/stdc++.h>
using namespace std;
int n, k, a, lst, ans;
set<int> st;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k); st.insert(0);
    for(int i = 1; i <= n; i++){
    	scanf("%d", &a); lst ^= a;
    	if(st.count(lst ^ k)) st.clear(), ans++;
    	st.insert(lst);
	}
	printf("%d", ans);
	return 0;
}

