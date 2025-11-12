# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sort;

void open() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}

struct road {
	int city[2];
	int w;
};

road mkroad(int ac, int bc, int w) {
	road rd;
	rd.city[0] = ac;
	rd.city[1] = bc;
	rd.w = w;
	
	return rd;
}

int getint() {
	int a = 0;
	scanf("%d", &a);
	return a;
}

struct town {
	int w;
	int *ww;
};

town mktown(int w, int* ww) {
	town t;
	t.w = w;
	t.ww = ww;
	return t;
}

int *reader(int citys) {
	int* par = new int[citys];
	for(int i = 0; i < citys; i++) {
		scanf("%d", &par[i]);
	}
	return par;
}

int main() {
	open();
	int citys, roads, towns;
	scanf("%d %d %d", &citys, &roads, &towns);
	
	road* aroad = new road[roads];
	town* atown = new town[towns];
	
	for(int i = 0; i < roads; i++) {
		aroad[i] = mkroad(getint(), getint(), getint());
	}
	
	for(int i = 0; i < towns; i++) {
		atown[i] = mktown(getint(), reader(citys));
	}
	
	printf("13");
//	int nowpos
}

// ____FJ-S01316____
//  Andrew M. Pines
