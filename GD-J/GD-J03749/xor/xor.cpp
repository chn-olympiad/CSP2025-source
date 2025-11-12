#include<bits/stdc++.h>
using namespace std;
int n , k;
int a[(int) 5e5 +7];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >>n >>k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans = 0;
    int tmp = 0;
    for(int l=1 , r=1 ; l <= r && r <= n;r++ ){
    	tmp ^= a[r];
    	if(tmp == k){
    		tmp = 0;
    		ans++;
    		l = r;
		}
	} 
    cout <<ans;
}

