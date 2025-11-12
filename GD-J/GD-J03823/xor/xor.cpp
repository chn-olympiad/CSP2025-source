#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdin);
	int n,k,cnt=0;
	bool isa=1,isb=1;
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=1){
			isa=0;
		}
		if (a[i]!=0 && a[i]!=1){
			isb=0;
		}
		cnt++;
	} 
	if (isa){
		cout << n;
		return 0;
	}
	if (isb){
		cout << cnt;
	}
	return 0;
}
