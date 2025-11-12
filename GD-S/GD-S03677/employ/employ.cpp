#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<deque>
#include<queue>
using namespace std;

int n,m;
struct node{
	int id,c;
	bool operator < (const node & nd) const{
		return id < nd.id;
	}
}a[11];
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> a[i].c,a[i].id = i;
	int ans = 0;
	do{
		int cnta = 0,cnt = 0;
		for(int i = 1;i <= n;i++){
			if(cnta >= a[i].c){
				cnta++;
				continue;
			}
			cnta += s[i-1] == '0';
			cnt += s[i-1] == '1';
		}
		if(cnt >= m) ans++;
	}while(next_permutation(a + 1,a + n + 1));
	cout << ans;
	return 0;
}