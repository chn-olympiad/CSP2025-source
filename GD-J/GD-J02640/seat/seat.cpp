#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("seat.in");
ofstream cout("seat.out");
int n, m, r, x, y, grade[100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> r;
	grade[0] = r, x = y = 1;
	for(int i=1; i<n*m; i++)
		cin >> grade[i];
	sort(grade, grade + n * m, [&]
	(int a, int b){ return a > b;});
	for(int i=0; i<n*m; i++){
		if(grade[i] == r)
		{cout << y << ' ' << x; break;}
		if((i + 1) % n == 0) y++;
		else x += (y & 1 ? 1 : -1);
	}
	return 0;
}
