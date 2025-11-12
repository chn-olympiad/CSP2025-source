// From ZZY 2025.11.1 数据范围给太小了吧
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream in("seat.in");
	ofstream out("seat.out");
	int n, m;
	in >> n >> m;
	vector<int> v(n * m);
	for (auto& e : v) in >> e;
	int sc = v[0], gt = 0;
	for (auto e : v) {
		if (e > sc) gt++;
	}

	int col = gt / n + 1;
	out << col << ' ' << ((col & 1) ? gt % n + 1 : n - (gt % n)) << '\n';
	return 0;
}
