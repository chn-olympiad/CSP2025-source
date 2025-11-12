#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a;
	int c[505];
	for(int i = 1;i<= n;i++) cin >> a;
	for(int i = 1;i <= n;i++) cin >> c[i];
	sort(c+1,c+n+1,cmp);
	
		return 0;
	}
	