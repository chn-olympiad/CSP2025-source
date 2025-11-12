#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	int cnt=0;
	int j=1;
	for(int i=1;i<=n;i++){
		int sum=0; 
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout << cnt << endl;
	return 0;
} 
