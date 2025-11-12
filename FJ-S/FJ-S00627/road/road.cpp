#include <bits/stdc++.h>
using namespace std;

struct Rode{
	int a;
	int b;
	int vl;
}r[1000000];
struct village{
	int vl;
	struct Road rv[1000000];
}v[11];
int n,m,k;

int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> r[i].a >> r[i].b >> r[i].vl;
	}
	
	return 0;
}
