#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout)
const int N = 110;
int n,m,a[N],me,seat;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	FILE("seat");
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	me = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(me == a[i]){
			seat = i-1;
		}
	}
	cout << seat / n + 1 << " " << ((seat / n + 1) % 2 == 1?seat%n+1:m-seat%n);
	return 0;
}

