#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int a[N],ans = 0;
int main (){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if(k == 0){
		for(int i = 1;i <= n;i ++ ){
			cin >> a[i];
			if(a[i] == 0){
				ans ++;
			}
		}
		cout << ans << endl;
	}else{
		for(int i = 1;i <= n;i ++ ){
			cin >> a[i];
			if((a[i] & 1) == 1){
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
