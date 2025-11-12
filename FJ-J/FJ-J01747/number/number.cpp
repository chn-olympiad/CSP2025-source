#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a = 0;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num.push_back(s[i] - '0');
			a++;
		}
	}
	sort(num.begin(),num.end());
	for(int i = a-1; i >= 0; i--){
		cout << num[i];
	}
	cout << endl;
	return 0;
}
