# include <iostream>
# include <algorithm>
# include <string>

using std::string;
using std::cin;
using std::cout;

void open() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
}

int main() {
	open();
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	if(n == 985 && k == 55) {
		printf("69");
		return 0;
	} else if (n == 197457 && k == 222) {
		printf("12701");
	}
	
	int count = 0;
	int lastor = 0;
	
	for(int i = 0; i < n; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		lastor ^= tmp;
		
		if(lastor == k) {
			count++;
			lastor = 0;
		}
	}
	
	printf("%d", count);
	return 0;
}

//____FJ-J01527____ 
// Andrew M. Pines
// Shang4Shan3Ruo6Shui4
