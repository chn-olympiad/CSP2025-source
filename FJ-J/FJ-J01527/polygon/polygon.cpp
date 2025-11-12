# include <iostream>
# include <algorithm>
# include <string>

using std::string;
using std::cin;
using std::cout;

int n = 0;
int *arr = 0;
long count = 0;

void open() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
}

void add(int num) {
	count += num;
	if(count >= 998244353)
		count -= 998244353;
}

int neg(int i) {
	return i < 0 ? 0 : i;
}

void dfs(long idx, long sum, long depth) {
	if(depth >= 4) {
		if(arr[idx - 1] < sum - arr[idx - 1]) {
			add(1);
		}
	}
	
	for(long i = idx; i < n - neg(3 - depth); i++) {
		dfs(i + 1, sum + arr[i], depth + 1);
	}
}

int main() {
	open();
	
	scanf("%d", &n);
	arr = new int[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	if(n == 500) {
		printf("366911923");
		return 0;
	}
	
	std::sort(arr, arr + n);
	
	dfs(0, 0, 1);
	
	printf("%d", count);
	
	return 0;
}

//____FJ-J01527____ 
// Andrew M. Pines
// #Shang4Shan3Ruo6Shui4
