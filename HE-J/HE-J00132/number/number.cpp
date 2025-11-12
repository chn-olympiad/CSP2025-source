#include<bits/stdc++.h>
using namespace std;
long long a[10],ans;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i = 0;i<=s.length();i++){
		if(s[i]>= 48 && s[i]<58){
			long long ls = s[i] - '0';
			a[ls]++;
		}
	}
	for(int i = 9;i>=0;i--){
			while(a[i]>0){
				ans = ans*10+i;
				a[i]--;
			}
	}
	cout << ans;
	return 0;
}
