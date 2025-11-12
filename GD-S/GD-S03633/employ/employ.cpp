#include <bits/stdc++.h> 
using namespace std;

const int Max = 505; 

int n, m, ans;
string s;

int c[Max];

queue <int> qz; //零出现的位置 

int main() {
	
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> s;
	for (int i=1;i<=n;i++) {
		cin >> c[i];
	}
	for (int i=1;i<=n;i++) {
		if (s[i]=='0') qz.push(i);
	}
	
	sort(c+1,c+n+1);
	auto pre = c.begin();
	for (int i=1;i<=q.size();i++) {
		auto it=upper_bound(c+1,c+n+1,i)-1;
		int len=it-pre; //耐心为i的人数
		if (i<q.top()) { //若耐心为i的人数比第i个0出现的位置还少 
			
		} 
	}
	
	
}
