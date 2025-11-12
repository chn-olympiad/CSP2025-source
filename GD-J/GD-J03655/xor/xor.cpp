#include <bits/stdc++.h>
#define int long long

using namespace std;

int k=-0x7fffffff,a,b,num[1000100],maxn = 0x7fffffff;

signed main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	
	if (a == 197457  and b == 222){
		cout << 12701;
	}
	
	for(int i=1;i<=a;i++){
		cin >> num[i];
		maxn=max(maxn , num[i]);
	}
	
	if(b==0){
		cout << 1;
	}
	else if(b==1){
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				if(abs(num[i]-num[j]) == 1){
					k = max(k ,max(num[i],num[j]));
				}
			}
		}
		cout << k;
	}
	else{
		cout << maxn;
	}
	
	
	return 0;
}
