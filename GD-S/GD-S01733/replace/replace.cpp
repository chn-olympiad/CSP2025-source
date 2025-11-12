#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
struct node{
	string s1,s2;
}a[N];
string t1,t2;
int check(string s,string t){
	for(int i = 0;i < t.length();i++){
		if(s[0] == t[i]){
			for(int k = 0;k < s.length();k++){
				if(s[k] != t[i + k])
					break;
			}
		}
	}
	return -1;
}
bool check(int l){
	for(int i = l;i < t1.length();i++){
		if(t1[i] != t2[i])
			return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> a[i].s1 >> a[i].s2;
	while(q--){
		cin >> t1 >> t2;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			int num1 = check(a[i].s1,t1);
			int num2 = check(a[i].s2,t2);
			if(num1 == num2 && num1 != -1 && check(num1 + a[i].s1.size()))
				ans++;	
		}
		cout << ans << endl;
	}
	return 0;
}
