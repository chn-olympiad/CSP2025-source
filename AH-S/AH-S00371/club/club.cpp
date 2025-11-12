#include<bits/stdc++.h>
using namespace std;
struct Person {
	int a, b, c;
	int go_for;
}people[100005];
int n;
long long maxsum = 0;
void dfs(long long sum_a,long long sum_b,long long sum_c,int num_a,int num_b,int num_c,int idx) {
	if (idx > n) {
		maxsum = max(maxsum, sum_a + sum_b + sum_c);
	}
	else {
		if(num_a + 1 <= n / 2) {
			dfs(sum_a + people[idx + 1].a,sum_b, sum_c,num_a + 1,num_b,num_c,idx + 1);
		}
		if(num_b + 1 <= n / 2) {
			dfs(sum_a,sum_b + people[idx + 1].b, sum_c,num_a,num_b + 1,num_c,idx + 1);
		}
		if(num_c + 1 <= n / 2) {
			dfs(sum_a,sum_b, sum_c + people[idx + 1].c,num_a,num_b,num_c + 1 ,idx + 1);
		}
	}
}
bool cmpa(Person x, Person y) {
	if(x.a != y.a) {
		return x.a > y.a;
	}
	else if (x.b != y.b) {
		return x.b > y.b;
	}
	else {
		return x.c > y.c;
	}
}
bool cmpb(Person x, Person y) {
	if (x.b != y.b) {
		return x.b > y.b;
	}
	else if (x.a != y.a) {
		return x.a > y.a;
	}
	else {
		return x.c > y.c;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T --) {
		cin >> n;
		bool flaga = true;
		bool flagb = true;
		for (int i = 1; i <= n; i ++) {
			cin >> people[i].a >> people[i].b >> people[i].c;
			if (people[i].b != 0 || people[i].c != 0) {
				flaga = false;
			}
			if (people[i].c !=0) {
				flagb = false;
			}
		}
		if (flaga == true) {
			long long ans = 0;
			sort(people + 1, people + n + 1, cmpa);
			for (int i = 1; i <= n / 2; i ++) {
				ans += people[i].a;
			}
			cout << ans << endl;
		}
		else if(flagb == true) {
			long long ansa = 0;
			long long ansb = 0;
			sort(people + 1, people + n + 1, cmpa);
			for (int i = 1; i <= n / 2; i ++) {
				ansa += people[i].a;
			}
			for (int i = n / 2 + 1; i <= n / 2 + n / 2; i ++) {
				ansa += people[i].b;
			}
			sort(people + 1, people + n + 1, cmpb);
			for (int i = 1; i <= n / 2; i ++) {
				ansb += people[i].b;
			}
			for (int i = n / 2 + 1; i <= n / 2 + n / 2; i ++) {
				ansb += people[i].a;
			}
			cout << max(ansa, ansb) << endl;
		}
		else {
			sort(people + 1, people + n + 1, cmpa);
			maxsum = 0;
			dfs (0, 0, 0, 0, 0, 0, 0);
			cout << maxsum << endl;
		}
	}
	return 0;
}
