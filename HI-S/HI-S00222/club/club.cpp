#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int m;
		cin >> m;
		int a,b,c;
		for(int i=1;i<=m;i++){
			cin >> a >> b >> c;
			sum+=max(max(a,b),max(b,c));
		}
		cout << sum << endl;
		sum=0;
	}
	return 0;
}
