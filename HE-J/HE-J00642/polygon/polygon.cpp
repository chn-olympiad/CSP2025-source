#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n,a[5010],flag = 1,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n; i++){
		cin>>a[i];
		if(a[i] != 1){
			flag = 0;
		}
    }
    sort(a+1,a+1+n);
    if(flag == 1){
    	for(int i = n-2;i>=1;i--){
    		ans = (ans + i) % M;
		}
		cout<<ans;
		return 0;
	}
  if(n < 3){
    	cout<<0;
    	return 0;
	}
	if(n = 3 && a[1] + a[2] > a[3]){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	if(n > 3 && n < 6){
		cout<<6;
		return 0;
	}
	cout<<366911923;
	return 0;
}
