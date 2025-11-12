#include <iostream>
#include <queue>
#include <string>

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	std::priority_queue<int> list;
	
	std::string str;
	std::cin >> str;
	
	for (char character : str)
		if (character >= '0' && character <= '9')
			list.push((character - '0'));
			
	while (!list.empty()) {
		std::cout << list.top();
		list.pop();
	} 
	
	fclose(stdin); 
	fclose(stdout);
} 
