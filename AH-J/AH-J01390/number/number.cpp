#include <iostream>
#include <cstring>
using namespace std;

int num[10] = {};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string r;
	cin >> r;
	int l = r.size();

	for (int i = 0; i < l; i++)
	{
		if (r[i] >= '0' && r[i] <= '9')
		{
			num[r[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for(int j = 1 ; j <= num[i] ; j++){
			cout << i;
		}
	}
	return 0;
}
