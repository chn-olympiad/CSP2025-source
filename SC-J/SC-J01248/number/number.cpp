#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e7;
string s;
ll a[N];
ll k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] && '9'>=s[i]){
			a[i-k]=s[i]-'0';
		}
		else{
			k++;
		}
	}
	sort(a,a+s.length()-k);
	for(int i=s.length()-1-k;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 