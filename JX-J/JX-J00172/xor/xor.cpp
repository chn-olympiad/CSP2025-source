#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
struct node{
	int l,r;
}o[N];
bool cmp(node A,node B){
	if(A.r != B.r) return A.r < B.r;
	return A.l < B.l;
}
int n,k,idx,ans,a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)
		s[i] = s[i - 1] ^ a[i];
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++){
			int sum = s[j] ^ s[i - 1];
			if(sum == k) o[++ idx] = {i,j};
		}
	sort(o + 1,o + idx + 1,cmp);
	int recl = -1,recr = -1;
	for(int i = 1 ; i <= idx ; i ++){
		int x = o[i].l,y = o[i].r;
		if(x > recr){
			recl = x,recr = y,ans ++;
			//cout << recl << ' ' << recr << '\n';
		}
	}
	cout << ans;
	return 0;
}
