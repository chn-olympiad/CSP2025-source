#include<bits/stdc++.h>
using namespace std;
int read(){
	int cnt = 0, sign = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	sign = -1;
		c = getchar();
	}
	while(isdigit(c)){
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * sign;
}
const int N = 2e5 + 10;
struct node{
	string fst, sec;
}st[N];
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for(int i = 1; i <= n; i++){
		cin >> st[i].fst >> st[i].sec;
	}
	sort(st + 1, st + n + 1, [](node a, node b){
		return a.fst.size() < b.fst.size();
	});
	while(q--){
		string st1, st2;
		cin >> st1 >> st2;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int fl1 = st1.find(st[i].fst), fl2 = st2.find(st[i].sec);
			if(fl1 <= st1.size() && fl2 <= st1.size() &&fl1 == st1.rfind(st[i].fst) && fl2 == st2.rfind(st[i].sec))	ans++;
			if(st[i].fst.size() > st1.size())	break;
		}
		printf("%d\n", ans);
	}
	return 0;
}

