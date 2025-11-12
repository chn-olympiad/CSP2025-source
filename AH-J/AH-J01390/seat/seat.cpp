#include <iostream>
#include <algorithm>
using namespace std;

int grade[10005] = {};
/**/
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> grade[1];
	int r = grade[1];
	for (int i = 2; i <= n * m; i++)
	{
		cin >> grade[i];
	}
	sort(grade + 1 , grade + n + m + 1);
	int index;
	for (int i = 1; i <= n * m; i++)
	{
		if (grade[i] == r)
		{
			index = i;
			break;
		}
	}
	if (index % (n * 2) - n > 0)
	{
		cout << (index + (n - 1)) / n << ' ' << n - index % n + 1;
	}
	else if(index % (n * 2) == 0){
		cout << index / n << ' ' << 1;
	}
	else if(index % n != 0){
		cout << (index + (n - 1)) / n << ' ' << index % n;
	}
	else{
		cout << (index + (n - 1)) / n << ' ' << n;
	}
	return 0;
}
