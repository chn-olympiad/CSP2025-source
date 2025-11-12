#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,t,r,c;
struct hh{
	int a,id;
}p[N];
bool cmp(hh i,hh j){
	return i.a > j.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> p[i].a;
		p[i].id = i;
	}
	sort(p+1,p+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
		if( p[i].id == 1 ){
			t = i;
			break;
		} 
	c = (t+n-1)/n;
	if( ( (t+n-1)/n%2 ) == 0) r = (n - (t-1)%n );
	else r = (t-1)%n + 1;
	cout << c <<" "<<r;
	return 0;
}
/*
1 1
100
ans : 1 , 1
4 2
30 10 20 40 50 60 70 80
ans : 2 , 3
4 2
10 20 30 50 60 70 80 40
ans : 2 , 1
*/
