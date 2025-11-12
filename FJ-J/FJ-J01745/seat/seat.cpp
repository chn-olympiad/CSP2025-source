#include <bits/stdc++.h>
#define N 12

int n,m;
int a[N * N];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		std::cin >> a[i];
	}
	int cur = a[1];
	std::sort(a + 1,a + n * m + 1,[](int a,int b){
		return a > b;
	});
	int id = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == cur){
			id = i;
			break;
		}
	}
	int lie = (id / n) + 1;
	int hang = id % n;
	if(hang == 0){
		hang = n;
		lie--;
	}
	if(lie % 2 == 0){
		hang = n - hang + 1;
	}
	std::cout << lie << " " << hang << '\n';
	return 0;
}

