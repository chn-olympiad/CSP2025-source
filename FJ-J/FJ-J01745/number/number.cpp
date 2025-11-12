#include <bits/stdc++.h>

std::string str;
std::string ans;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> str;
	for(char i : str){
		if(i >= '0' && i <= '9'){
			ans += i;
		}
	}
	std::sort(ans.begin(),ans.end(),[](char a,char b){
		return a > b;
	});
	std::cout << ans;
	return 0;
}

