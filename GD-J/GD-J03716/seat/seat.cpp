#include<bits/stdc++.h>
using namespace std;
int n , m , w;
struct str{
	int f , id;
}a[110];
bool cmp(str x , str y){
	return x.f > y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i].f;
		a[i].id = i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i].id == 1) w = i;
	}
	cout << (w-1)/n+1 << " ";
	if((w-1)/n%2 == 0) cout << (w-1)%n+1;
	else if((w-1)/n%2 == 1) cout << n-((w-1)%n);
	return 0;
}
