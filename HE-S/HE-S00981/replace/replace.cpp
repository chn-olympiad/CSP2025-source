#include<bits/stdc++.h>
#include<map>
using namespace std;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin >> n >> q;
	map<string,string>m;
	for(int i = 0;i < n;i++){
		string t1,t2;cin >> t1 >> t2;
		m[t1] = t2;
	}
	for(int o = 0;o < q;o++){
		int cot = 0;
		string s1,s2;cin >> s1 >> s2;
//		if(m[s1]==s2)	
		string t1,t2;
		for(int i = 0;i <s1.size();i++){
			if(s1[i]!=s2[i]){
				t1 += s1[i];t2 += s2[i];
			}
			
		}
		
		if(m[s1] == s2){
			cot++;
		}
		if(m[t1] == t2){
			cot++;
		}
		cout << cot << endl;
		}
	return 0;
}
