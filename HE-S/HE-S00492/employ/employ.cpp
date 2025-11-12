#include<bits/stdc++.h>
using namespace std;
int const N = 1e7 + 5;
int n,m,ps;
string d;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> d;
	for(int i = 0;i < m;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		if(d[i] == 0){
			ps++;
		}
		a[i] = ps;
	}
	sort(a,a + m);
	cout << n;
}
