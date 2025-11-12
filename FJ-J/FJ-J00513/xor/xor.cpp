#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	long long n, k, num[500005];
	cin>>n>>k;
	for(int i = 1; i<=n; i++){
		cin>>num[i];
	}
	
	
	int l = 1, r = 1, cnt = 0, sum = 0, i = 1;
	
	while(r<=n && l<=n){
		sum = sum^num[i];
		if(sum == k){
			cnt++;
			l = r+1;
			r++;
			sum = 0;
		}
		else r++;
		i++;
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
