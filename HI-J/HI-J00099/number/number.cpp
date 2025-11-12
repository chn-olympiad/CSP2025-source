#include<bits/stdc++.h> 
using namespace std;
char s,a,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a;
		n = max(a);
	}
	cout << n;
	return 0;
}
