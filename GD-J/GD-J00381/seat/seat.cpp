#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> v;
	int a;
	for(int i = 1;i <= n * m;i++){
		cin >> a;
		v.push_back(a);
	}
	a = v[0];
	sort(v.begin(),v.end(),cmp);
	int cnt;
	for(int i = 0;i < v.size();i++) if(v[i] == a) cnt = i + 1;
	int c;
	if(cnt % n == 0) c = cnt / n;
	else c = cnt / n + 1;
	int r;
	if(c % 2 == 0) r = n - cnt % n + 1;
	else{
		if(cnt % n == 0) r = n;
		else r = cnt % n;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
