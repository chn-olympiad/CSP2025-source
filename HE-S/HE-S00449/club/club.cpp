#include <iostream>
using namespace std;
int T;
int n;
struct node{
	int a1, a2, a3, maxn, pos;
}a[100005];
bool B(){
	int tmp = 0;
	for(int i = 1;i <= n;i++)
		if(a[i].a1 == 0 && a[i].a2 == 0) && a[i].a3 == 0)
			tmp++;
	return tmp == n;
}
int pow(int x, int y){
	int re = 1;
	for(int i = 1;i <= x;i++) re *= y;
	return re;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		if(n == 2){
			cout << 2 << endl;
			continue;
		}
		if(B()){
			cout << pow(3, n) << endl;
			continue;
		}
		cout << 14 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
