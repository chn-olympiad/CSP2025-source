#include <fstream>
using namespace std;
ifstream cin("number.in");
ofstream cout("number.out");
string code; int cnt[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> code;
	for(char i : code)
		if('0' <= i && i <= '9')
			cnt[i - '0']++;
	for(int i=9; i>=0; i--)
		while(cnt[i]--) cout << i;
	return 0;
}
