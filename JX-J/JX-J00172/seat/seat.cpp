#include<bits/stdc++.h>
using namespace std;
const int N = 110;
struct stu{
	int id,gr;
}a[N];
int n,m,x,idx;
bool cmp(stu A,stu B){
	return A.gr > B.gr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	x = n * m;
	for(int i = 1 ; i <= x ; i ++){
		cin >> a[i].gr;
		a[i].id = i;
	}
	sort(a + 1,a + x + 1,cmp);
	for(int i = 1 ; i <= m ; i ++)
		if(i % 2 == 1)
			for(int j = 1 ; j <= n ; j ++){
				int now = a[++ idx].id;
				if(now == 1){
					cout << i << ' ' << j;
					return 0;
				}
			}
		else
			for(int j = n ; j >= 1 ; j --){
				int now = a[++ idx].id;
				if(now == 1){
					cout << i << ' ' << j;
					return 0;
				}
			}
	return 0;
}
