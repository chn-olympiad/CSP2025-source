#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define lnf 0x3f3f3f3f
const int maxn = 1e6 + 10;
int n,q;
string s1[maxn],s2[maxn];
string t1,t2;

int main(){
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		int ans = 0;
		cin >> t1 >> t2;
		for(int i = 0;i < n;i++){
			int id = t1.find(s1[i]);
//			cout << id << "\n";
			int len = s1[i].length();
			string x,z;
			for(int j = 0;j < id;j++){
				x+=s1[i][j];
			}
			for(int j = id+len;j < s1[i].length();j++){
				z+=s1[i][j];
			}
			string t3 = x + s2[i] + z;
//			cout << x << " " << s2[i] << " " << z <<"\n" << t3 << "\n";
			if(t3 == t2)ans++;
			
		}
		cout << ans << "\n";
	}
}
