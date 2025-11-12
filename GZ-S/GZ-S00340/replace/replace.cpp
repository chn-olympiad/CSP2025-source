//GZ-J00366 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	long long s1=0;
	cin >> n >> m;
	vector<int> a(n+1);
	a[0] = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	if(m <= 1){
		for(int i = 2;i <= m;i++) {
			if(a[i] != a[i-1]){
				for(int i = m+1;i <= n;i++) {
					if(a[i] != a[i-1]){
						cout << 1;
						return 0;
					}
				}
				cout << 0;
				return 0;
			}
		}	
		cout << 0;
		return 0;
	} 
	cout << 2;
	return 0;
}
