#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, S = 5e6 + 10;
int n, q;
string s1[N], s2[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> s1[i] >> s2[i];
	
	for(int i = 0; i < q; i++){
		string t1, t2;
		char t[S];
		int res = 0;
		cin >> t1 >> t2;
		for(int i = 0; i < t1.size(); i++)
			for(int j = 0; j < n; j++)
				if(t1[i] == s1[j][0]){
					bool flag = true;
					for(int k = 1; k < s1[j].size(); k++){
						if(t1[i + k] == s1[j][k]) t[i + k] = s2[j][k];
						else{
							flag = false;
							break;
						}
					}
					if(flag){
						for(int k = 0; k < i + s1[j].size(); k++)
							if(t[k] != t2[k]){
								flag = false;
								break;
							}
						for(int k = i + s1[j].size(); k < t1.size(); k++)
							if(!flag || t1[k] != t2[k]){
								flag = false;
								break;
							}
						if(flag) res++;
					}
				}
	}
	
	return 0;
}
