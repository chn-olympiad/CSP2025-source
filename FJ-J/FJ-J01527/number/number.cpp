# include <iostream>
# include <algorithm>
# include <string>

using std::string;
using std::cin;
using std::cout;

void open() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
}

bool compare(int a, int b) {
	return a > b;
}

int main() {
	open();
	
	string s = "";
	cin >> s;
	
	int numbers = 0;
	int *nums = new int[s.size()];
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			nums[numbers] = s[i] - '0';
			numbers++;
		}
	}
	
	std::sort(nums, nums + numbers, compare);
	
	for(int i = 0; i < numbers; i++) {
		printf("%d", nums[i]);
	}
	
	return 0;
}

//____FJ-J01527____ 
// Andrew M. Pines
// #Shang4Shan3Ruo6Shui4
