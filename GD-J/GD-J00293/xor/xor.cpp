#include<bits/stdc++.h>
using namespace std;
long long a[500001],prefix[500001],chosen[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	prefix[0] = a[1];
	long long n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		prefix[i] = a[i] ^ prefix[i-1];
	}
	bool flag = true;
	int cnt = 0;
	while(flag){
		flag = false;
		for(int i=1;i<=n;i++){
			if(flag == true){
				break;
			}
			if(chosen[i] != 0){
				continue;
			}
			for(int j=i;j<=n;j++){
				if(chosen[j] != 0){
					continue;
				}
				if(i == 1){
					if(prefix[j] == k){
						cnt ++ ;
						flag = true;
						for(int k=i;k<=j;k++){
							chosen[k] = 1;
						}
						break;
					}
				}
				else{
					if((prefix[j] ^ prefix[i-1]) == k){
						cnt ++ ;
						flag = true;
						for(int k=i;k<=j;k++){
							chosen[k] = 1;
						}
						break;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
