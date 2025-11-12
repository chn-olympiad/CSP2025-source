#include<iostream>
using namespace std;
int n;
int s[5120];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n<3)cout<< 0;
	for(int i=1;i<=n;i++) cin >> s[i];
	int big=s[1];
	for(int i=2;i<=n;i++){
		if(big<s[i]) big==s[i];
	}
	if(s[1]+s[2]+s[3]>big*2) cout << 1;
	else cout << 0;
	return 0;
}
