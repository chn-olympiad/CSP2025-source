#include <bits/stdc++.h>
using namespace std;
long long m4a1[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> m4a1[i]; 
	}
	int cnt1=0;
	int num1=m4a1[1];
	for(int i=2;i<=n;i++){
		if(num1==k){
			cnt1++; 
			num1=m4a1[i];
		}
		else{
			num1=num1^m4a1[i];
		}
	}
	if(num1==k){
		cnt1++;
	}
	int cnt2=0;
	int num2=m4a1[n];
	for(int i=n-1;i>=1;i--){
		if(num2==k){
			cnt2++; 
			num2=m4a1[i];
		}
		else{
			num2=num2^m4a1[i];
		}
	}
	if(num2==k){
		cnt2++;
	}
	cout << max(cnt1,cnt2);
	return 0;
}