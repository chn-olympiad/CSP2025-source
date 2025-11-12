#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;

struct Student {
	int score,id;
};

Student stu[N + 5];

bool cmp(const Student &a,const Student &b) {
	return a.score > b.score;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for (int i = 1;i <= n * m;i++) {
		cin >> stu[i].score;
		
		stu[i].id = i;
	}
	
	sort(stu + 1,stu + n * m + 1,cmp);
	
	int i = 1,j = 1,k = 1,dlt = 1;
	while (stu[k].id != 1) {
		if (((i & 1) == 1 && j == n) || ((i & 1) == 0 && j == 1)) {
			i++;
			dlt = -dlt;
		} else {
			j += dlt;
		}
		k++;
	}
	
	cout << i << " " << j << endl;
	return 0;
}
