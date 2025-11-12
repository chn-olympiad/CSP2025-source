#include <iostream>
#include <algorithm>
using namespace std;

struct satis{
	int a, b, c;
}a[100005], b[100005], c[100005];

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		sort(a, a+n+1, cmp)
		
	}
	return 0;
} 
