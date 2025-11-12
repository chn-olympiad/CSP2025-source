# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sort;

# define INTMAX 2147483647

void open() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}

struct sats {	
	int *arr;
	
	int most() {
		int max = 0;
		int idx = 0;
		for(int i = 0; i < 3; i++)
		{
			if(arr[i] > max) {
				max = arr[i];
				idx = i;
			}
		}
		return idx;
	}
	
	int least() {
		int min = INTMAX;
		int idx = 0;
		for(int i = 0; i < 3; i++)
		{
			if(arr[i] < min) {
				min = arr[i];
				idx = i;
			}
		}
		return idx;
	}
	
	int sum() {
		return arr[0] + arr[1] + arr[2];
	}
	
	int pole() {
		return arr[most()] - arr[least()];
	}
	
	bool compare(sats b) {
		return pole() == b.pole() ? sum() < b.sum() : pole() > b.pole();
	}
};

sats make(int a, int b, int c) {
	sats x;
	x.arr = new int[3] {a, b, c};
	return x;
}

int getint() {
	int a = 0;
	scanf("%d", &a);
	return a;
}

bool compare(sats a, sats b) {
	return a.compare(b);
}

int solve() {
	int n = 0;
	scanf("%d", &n);
	
	sats* arr = new sats[n];
	
	for(int i = 0; i < n; i++) {
		arr[i] = make(getint(), getint(), getint());
	}
	
	int max = n / 2;
	sort(arr, arr + n, compare);
	sats total = make(0, 0, 0);
	int allsats = 0;
	
	for(int i = 0; i < n; i++) {
		total.arr[arr[i].most()] ++;
		allsats += arr[i].arr[arr[i].most()];
	}

	while(total.arr[total.most()] > max) {
		int a = total.least();
		int b = 3 - total.most() - total.least();
		
		int alst = INTMAX;
		int aidx = -1;
		int blst = INTMAX;
		int bidx = -1;
		for(int i = 0; i < n; i++) {
			if(arr[i].most() == total.most()) {
				if(arr[i].arr[arr[i].most()] - arr[i].arr[a] < alst) {
					aidx = i;
					alst = arr[i].arr[arr[i].most()] - arr[i].arr[a];
				}
				if(arr[i].arr[arr[i].most()] - arr[i].arr[b] < blst) {
					bidx = i;
					blst = arr[i].arr[arr[i].most()] - arr[i].arr[b];
				}
			}
		}
		if(alst < blst) {
			allsats -= alst;
			arr[aidx].arr[arr[aidx].most()] = -1;
			total.arr[total.most()] --;
			total.arr[a] ++;
		} else {
			allsats -= blst;
			arr[bidx].arr[arr[bidx].most()] = -1;
			total.arr[total.most()] --;
			total.arr[b] ++;
		}
	}
	
	return allsats;
}

int main() {
	open();
	int grps = 0;
	scanf("%d", &grps);
	
	for(int i = 0; i < grps; i++) {
		printf("%d \n", solve());
	}
	
	return 0;
}

// ____FJ-S01316____
//  Andrew M. Pines
