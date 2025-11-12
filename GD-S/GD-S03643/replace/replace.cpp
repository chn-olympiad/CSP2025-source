#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, L = 5e6 + 5;
map<string, vector<string> > mp;
int n, q;
string s1, s2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		int l = 0, r = s1.size() - 1;
		while(s1[l] == s2[l]) l++;
		while(s1[r] == s2[r]) r--;
		string temp1, temp2;
		for(int i = l; i <= r; i++) temp1 += s1[i], temp2 += s2[i];
		mp[temp1].push_back(temp2); 
	}
	while(q--){
		cin >> s1 >> s2;
		int l = -1, r = -1, flag = 0;
		string tmp, tar;
		for(int i = 0; i < s1.size(); i++){
			if(s1[i] != s2[i]){
				if(l == -1){
					l = i;
					tmp += s1[i], tar += s2[i];
				}else if(s1[i - 1] != s2[i - 1]){
					r = i;
					tmp += s1[i], tar += s2[i];
				}else{
					flag = 1;
					break;
				}
			}
		}
		if(flag){
			printf("0\n");
			continue;
		}
		if(mp[tmp].empty()){
			printf("0\n");
			continue;
		}
		int cnt = 0;
		for(int i = 0; i < mp[tmp].size(); i++){
			if(mp[tmp][i] == tar) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
