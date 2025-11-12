#include <bits/stdc++.h>
using namespace std;
long long b[1000005],s=1; 
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i=0;i < a.size();i++){
		if(a[i]<='9' && a[i]>='0'){
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b+1,b+s);
	for(int i=s-1;i>=1;i--){
		cout << b[i];
	}
	return 0;
}

