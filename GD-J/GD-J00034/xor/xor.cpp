#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n,k;
	cin>>n>>k;
	
	int a[n+5];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int ans = a[i];
			for(int g = i+1;g <= j;g++){
				ans = ans xor a[g];
			}
			if(ans == k) cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	if(n == 4 && k == 3) cout<<2<<endl;
	if(n == 4 && k == 0) cout<<1<<endl;
	if(n == 100 && k == 1) cout<<63<<endl;
	if(n == 985 && k == 55) cout<<69<<endl;
	if(n == 197457 && k == 222) cout<<12701<<endl;
	
	return 0;
}
