# include <iostream>
# include <algorithm>
# include <string>

using std::string;
using std::cin;
using std::cout;

void open() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
}

bool compare(int a, int b) {
	return a > b;
}

int main() {
	open();
	
	int n, m;
	
	scanf("%d %d", &n, &m);
	int t = n * m;
	int *arr = new int[t];
	
	for(int i = 0; i < t; i++) {
		scanf("%d", &arr[i]);
	}
	
	int p = arr[0];
	std::sort(arr, arr+t, compare);
	
	int pos = 0;
	int i = 1; 
	int j = 1;
	
	bool found = false;
	
	for(;i <= m; i++) {
		if(i % 2 == 1) {
			for(j = 1; j <= n; j++, pos++) {
				if(arr[pos] == p) {
					found = true;
					break;
				}
			}
		} else {
			for(j = n; j >= 1; j--, pos++) {
				if(arr[pos] == p) {
					found = true;
					break;
				}
			}
		}
		
		if(found) {
			break;
		}
	}
	
	printf("%d %d", i, j);
	
	return 0;
}

//____FJ-J01527____ 
// Andrew M. Pines
// #Shang4Shan3Ruo6Shui4
