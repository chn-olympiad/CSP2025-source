#include<bits/stdc++.h>
#define ll long long
#define inf INT_MAX
#define linf LLONG_MAX
using namespace std;
ll n, q, pi1[500000], pi2[500000], pi3[500000], pi4[500000];
string s1[200004], s2[200005], str1, str2;
bool err[200005];
void kmp(string a, string b, ll* arr){
	string t = a + "#" + b;
	ll len = t.size();
	fill(arr, arr + len + 1, 0);
	for(int i = 1; i < len; i++){
		ll j = arr[i - 1] + 1;
		while(j > 0 && t[i] != t[j - 1]){
			j = arr[j - 1];
		}
		arr[i] = j;
	}
}
bool check(ll len1, ll len2, ll debug){
	ll flag = false, cnt = 0;
	string t1 = str1, t2 = str2;
	for(int i = len1 + 1; i < len1 + len2 + 1; i++){
		if(pi2[i + len1 - 1] == len1 && pi1[i + len1 - 1] == len1){
			for(int j = i - len1 - 1; j < i - 1; j++){
				t2[j] = t1[j];
			}
			break;
		}
	}
	if(t1 != t2){
		return false;
	}
	for(int i = len1 + 1; i < len1 + len2 + 1; i++){
		if(pi1[i] == len1){
			if(!( (pi2[i] == len1) ^ (pi3[i] == len1) )){
				return false;
			}
		}
	}
	return true;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 0; i < q; i++){
		ll ans = 0;
		cin >> str1 >> str2;
		ll len = str1.size();
//		for(int j = 0; j < len; j++){
//			err[j] = (str1[j] != str2[j]);
//		}
		for(int j = 0; j < n; j++){
			kmp(s1[j], str1, pi1);
			kmp(s2[j], str2, pi2);
			kmp(s1[j], str2, pi3);
//			kmp(s2[j], str1, pi4);
			if(check(s1[j].size(), len, j)){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return (0 - 0);
}

