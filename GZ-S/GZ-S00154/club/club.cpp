//GZ-S00154 安顺市第一高级中学 张家豪

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;



struct stua{
	int a, c;
	bool visa;
	int numa;
}pa[100010];

struct stub{
	int b;
	bool visb;
	int numb;
}pb[100010];


bool cmpa(stua o, stua q) {
	return o.a >= q.a;
}

bool cmpb(stub o, stub q) {
	return o.b >= q.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);


	int t;
	int n;
	
	cin >> t;

	while(t--) {
		bool A, B = false;
		int a1 = 0, b1 = 0, c1 = 0;
		unsigned long long sum = 0;

		cin >> n;
		for(int i = 1; i <= n; i++) {
			A = B = false;
			cin >> pa[i].a >> pb[i].b >> pa[i].c;
			pa[i].numa = i;
			pb[i].numb = i;
			pa[i].visa = false;
			pb[i].visb = false;
			if(pa[i].c == 0 && pb[i].b != 0) B = true;
			if(pb[i].b == 0 && pa[i].c == 0) A = true;
		}
		
		unsigned long long sum1 = 0, sum2 = 0;

		if(B) {


			while(1) {
			
				int cnt = 1;
				if(cnt == n / 2) break;
				
				
				
				
			}
			cout << sum1 + sum2 << endl;
		}
		if(A) {
			sort(pa + 1, pa + n + 1, cmpa);
			for(int i = 1; i <= n / 2; i++) {
				sum1 += pa[i].a;
			}
			cout << sum1 << endl;
		}
		
		
	
		
	}

	return 0;
}
