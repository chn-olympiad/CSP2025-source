#include <bits/stdc++.h>
using namespace std;
struct node{
	int score;
	bool is_R;
};
bool cmp(node a, node b){
	return a.score > b.score;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector <node> a(n*m);
	for(int i = 0; i < n * m; i++){
		scanf("%d", &a[i].score);
		if(i == 0) a[i].is_R = true;
		else a[i].is_R = false;
	}
	sort(a.begin(), a.end(), cmp);
	int x;
	for(int i = 0; i < n * m; i++){
		if(a[i].is_R){
			x = i + 1;
			break;
		}
	}
	int c, l;
	c = ceil(x * 1.0 / n);
	printf("%d ", c);
	if(c % 2 == 1) l = x % n;
	else l = n + 1 - x % n;
	if(l == 0) printf("%d", n);
	else if(l == n + 1) printf("1");
	else printf("%d", l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
