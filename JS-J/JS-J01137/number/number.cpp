#include <bits/stdc++.h>
using namespace std;
int num[1000005],n = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int s = a.size();
	for(int i = 0;i < s;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			num[++n] = (int)(a[i] - '0');
		}
	}
	sort(num + 1,num + n + 1);
	for(int i = n;i >= 1;i--){
		cout << num[i];
	}
}
