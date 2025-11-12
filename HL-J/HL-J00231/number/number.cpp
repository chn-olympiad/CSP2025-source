#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
string a;
int sum[N];
long long j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>a;
	for(int i = 0;i < a.length();i++){
		if(a[i] >= '0' && a[i] <= '9'){
			j++;
			sum[j] = a[i]-'0';
		}
	}
	sort(sum+1,sum+j+1);
	for(int i = j;i >= 1;i--){
		cout <<sum[i];
	}
	return 0;
}
