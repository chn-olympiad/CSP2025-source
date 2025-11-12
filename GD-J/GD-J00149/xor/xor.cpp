#include<iostream>
using namespace std;

int n,k;
int a[200005];
int cnt1,cnt2;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] == 1) cnt2++;
		else cnt1++;
	}
	if (k == 0){
		cout << max(cnt1,(int)(cnt1 / 2) + (int)(cnt2 / 2));
		return 0;
	}
	if (k == 1){
		cout << cnt2;
		return 0;
	}
}
