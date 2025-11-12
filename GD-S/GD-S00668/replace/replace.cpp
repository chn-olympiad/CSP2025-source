#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
pair<string, string>str[N];
int main (){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		cin >> str[i].first >> str[i].second;
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			puts("0");
			continue;
		}
		int cnt = 0;
		int idx = 0;
		while(s1[idx] == s2[idx])
			idx++;
		int idx2 = s1.size()-1;
		while(s1[idx2] == s2[idx2])
			idx2--;
		for(int i = 1; i <= n; i++){
			auto a = s1.find(str[i].first);
			if(a == s1.npos)
				continue;
			auto b = s2.find(str[i].second);
			if(b == s2.npos)
				continue;
			if(a != b)
				continue;
			if(a > idx)
				continue;
			if(a+str[i].first.size()-1 < idx2)
				continue;
			cnt++;
//			str1 = s1;
//			str2 = s2;
//			while(s1.find())
		}
		printf("%d\n", cnt);
	}
}
