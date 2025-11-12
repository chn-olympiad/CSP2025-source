#include<bits/stdc++.h>
using namespace std;
string a[10005];
string b[10005];
string s1[10005];
string s2[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n = 0, q = 0,cnt = 0;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < q; i++){
		string t1,t2;
		cin >> t1 >> t2;
		int p = 0;
		for(int j = 0; j < t1.size(); j++){
			string t3;
			for(int k = j; k <= t1.size(); k++){
				t3 += t1[k];
				s1[p] = t3;
				p++;
			}
		}
		for(int j = 0; j < t2.size(); j++){
			string t3;
			for(int k = j; k <= t2.size(); k++){
				t3 += t2[k];
				s2[p] = t3;
				p++;
			}
		}
		for(int j = 0; j <= p; j++){
			for(int i = 0; i < n; i++){
				if(s1[j] == a[i]){
					if(s2[j] == b[i]){
						cnt++;
					}
				}
			}
		}
		cout << cnt << endl; 
	}
	return 0;
}




