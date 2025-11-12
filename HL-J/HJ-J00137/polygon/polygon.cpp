#include<bits/stdc++.h>
using namespace std;
const int N= 1e6+10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	cout << (n*3-1)/2 << endl;
	return 0;
}
//(/._./)   (>_<)  (>._.<)  (>x_x<)  (-_-^)  (/^._.^/)
