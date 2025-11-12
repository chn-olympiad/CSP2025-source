#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ci;
int fst;
bool cp(int a,int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n * m; i++) {
		int tmp;
		scanf("%d",&tmp);
		if (i == 0) fst = tmp;
		ci.push_back(tmp);
	}
	sort(ci.begin(),ci.end(),cp);
	int pm;
	for (int i = 0; i < n * m; i++) {
		if (ci[i] == fst) {
			pm = i;
			break;
		}
	}
	printf("%d %d\n",pm/n+1,((pm/n)%2==0)?pm%n+1:n-pm%n);
} 
