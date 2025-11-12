#include<bits/stdc++.h>
using namespace std;
int n,m;
struct no{
	int a;
	bool d;
}s[105];
bool cmp(no x,no y){
	return x.a > y.a;
}
int tot;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> s[i].a;
		s[i].d = 0;
	}
	s[1].d = 1;
	sort(s + 1,s + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i ++){
		if(s[i].d){
			tot = i;
			break;
		}
	}
	int l = (tot - 1) / n;
	int h = (tot - 1) % n + 1;
	l ++;
	if(l & 1){
		cout << l << ' ' << h;
	}
	else{
		cout << l << ' ' << (n - h) + 1;
	}
	return 0;
}
