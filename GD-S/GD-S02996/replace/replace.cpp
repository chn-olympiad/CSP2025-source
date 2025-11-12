#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

int n,q;
const int N = 1e7 + 10,M = 2e5 + 10;
int que[N];
int hh,tt;
std::string a[M];
std::string b[M]; 

int main () {
	std::freopen("replace.in","r",stdin);
	std::freopen("replace.out","w",stdout);	
	std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
	std::cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i] >> b[i];
	}
	while(q --) {
		int cnt = 0;
		std::string str1,str2;
		std::cin >> str1 >> str2;
		for (int i = 1; i <= n; i ++) {
			int pos = str1.find(a[i],0);
			while (1) {
				if (pos == -1) break;
				std::string tmp;
				tmp = str1;
				int y = b[i].size();
				for (int j = pos; j < pos + y; j ++) {
					str1[j] = b[i][j - pos];
				}
				if (str1 == str2) cnt ++;
				str1 = tmp;
				pos = str1.find(a[i],pos + 1); 
			}
		}
		std::cout << cnt << '\n';
	}
	return 0;
}
