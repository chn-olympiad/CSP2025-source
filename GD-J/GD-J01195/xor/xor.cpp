#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

std::array <int, 500010> arr;
std::array <bool, 500010> vis={};
std::vector <int> vec[500010];

int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out","w", stdout);
	
	int n, k;
	std::cin >> n >> k;
	for (int i=0; i<n; i++)
		std::cin >> arr[i];
	
	int ans=0;
	
	for (int i=0; i<n; i++) {
		vec[i].push_back(arr[i]);
		if (vec[i][0] == k && vis[i] == false) {
//			std::cout << i << ' ' << i << std::endl;
			ans ++; 
			vis[i] = true;
		}
	}
	for (int j=1; j<n; j++)
		for (int i=0; i<n; i++) {
			if (i+j>=n)
				continue;
			vec[i].push_back(vec[i][j-1] ^ arr[i+j]);
//			std::cout << "vec[" << i << "][" << i+j << "]:" << vec[i][j] << ' ';
			if (vec[i][j] == k) {
//				std::cout << i << ' ' << j+i << std::endl;
				bool flag = false;
				for (int l=i; l<=j+i; l++)
					if (vis[l] == true) {
						flag = true;
						break;
					}
				if (flag)
					break;
				ans ++;
				for (int l=i; l<=j+i; l++)
					vis[l] = true;
			}
	//	std::cout << std::endl;
		}
	std::cout << ans;
}
