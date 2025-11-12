#include<bits/stdc++.h>
using namespace std;
int A[500010],cnt;
struct node{
	int l,r;
	bool operator < (const node &o) const {
		if(r != o.r)return r < o.r;
		return l < o.l;
	}
};
node t[500010];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> A[i];
	for(int i = 1;i <= n;i++){
		int sum = A[i];
		if(sum == k){
			t[++cnt].l = i;
			t[cnt].r = i;
			continue; 
		}
		for(int j = i + 1;j <= n;j++){
			sum = (sum ^ A[j]);
			if(sum == k){
				t[++cnt].l = i;
				t[cnt].r = j;
				break; 
			}
		}
	}
	sort(t + 1,t + 1 + cnt);
	int ans = 0,pre = 0;
	for(int i = 1;i <= cnt;i++){
		if(t[i].l > pre){
			ans++;
			pre = t[i].r;
		}
	}
	cout << ans;
	
	return 0;
}
