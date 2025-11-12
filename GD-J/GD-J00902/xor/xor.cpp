#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 31;

int n,k,a[N],s[N];
set<int> st;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	s[0] = 0;
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]), s[i] = s[i - 1] ^ a[i];
	int ans = 0;
	st.insert(0);
	for(int i = 1;i <= n;i++){
		if(st.count(s[i] ^ k)){
			st.clear();
			ans++;
		}
		st.insert(s[i]);
	}
	printf("%d\n",ans);
	return 0;
}
