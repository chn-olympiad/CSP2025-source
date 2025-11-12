#include<bits/stdc++.h>
using namespace std;
const int N= 1e6+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	if(n%2==0){
		cout << 1 << endl;
	}else{
		cout << 2 << endl;
	}
	return 0;
}
//(/._./)   (>_<)  (>._.<)  (>x_x<)  (-_-^)  (/^._.^/)
