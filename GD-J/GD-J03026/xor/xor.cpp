#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long Max=-100000000000,ans=0,k,n;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			ans=0;
			for(int z=i;z<=j;z++){
				ans^=a[z];
			}
			if(ans==k){
				if(j-i+1>Max){
					Max=j-i+1;
				}
			}
		}
	}
	if(Max<0){
		cout << 0;
		return 0;
	}
	cout << Max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
