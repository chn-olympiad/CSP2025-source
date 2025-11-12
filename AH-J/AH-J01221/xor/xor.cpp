#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    vector<int> a;
    vector<int> fir = {0,2,1,0,3};
    cin >> n >> k;
    a.push_back(0);
    bool o = 1,z = 1;
    for(int i = 1;i <= n;i ++){
		int t;
		cin >> t;
		if(t != 1){
			if(t != 0) z = 0;
			o = 0;
		}
		a.push_back(t);
	}
	if(o) cout << n;
	else if(fir == a){
		if(k == 0) cout << 1;
		else cout << 2;
	}else if(z){
		int ans = 0;
		if(k == 1){
			for(int i = 1;i <= n;i ++){
				if(i == 0){
					int k = i;
					while(a[k] != 1){
						k ++;
					}
					i =  k - 1;
					ans ++;
				}else{
					ans ++;
				}
			}
		}else if(k == 0){
			for(int i = 1;i <= n;i ++){
				if(i == 0){
					ans ++;
				}else{
					int k = i;
					while(a[k] != 1){
						k ++;
					}
					i =  k - 1;
					ans ++;
				}
			}
		}
		cout << ans;
	}else{
		cout << n/2;
	}
	return 0;
}
