#include <bits/stdc++.h>
using namespace std;
const int L = 5e6+10;
int n,q,ans;
vector<string> s1;
vector<string> s2;
int pi[L];
int index[L];
int k = 0;
bool f = false;
void kmp1(string p){
	for (int i = 1;i < p.size();i++){
		int j = pi[i-1];
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) j++;
		p[i] = j;
	}
}
bool kmp2(string s, string p){
	k = 0;
	bool flag = false;
	int j = 0;
	for (int i = 0;i < s.size();i++){
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()){
			index[k] = i - p.size();
			flag = true;
			j = pi[j-1];
			k++;
		}
	}
	return flag;
}
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		string a,b;
		cin >> a;
		cin >> b;
		s1.push_back(a);
		s2.push_back(b);
	}
	for (int y = 1;y <= q;y++){
		memset(pi,0,sizeof(pi));
		string a,b;
		cin >> a;
		cin >> b;
		for (int v = 1;v <= n;v++){
			kmp1(s1[v]);
			f = kmp2(a,s1[v]);
			if (!f) continue;
			else{
				bool w = true;
				for (int i = 0;i < k;i++){
					for (int j = 0;j < index[i];j++){
						if (a[j] - b[j]!=0) w = false;
					}
					if (!w) continue;
					for (int j = index[i];j < index[i]+s1[v].size();j++){
						if (s2[v][j] -b[j] != 0) w = false;
					}
					if (!w) continue;
					for (int j = index[i]+s1[v].size();j < b.size();j++){
						if (a[j] - b[j]!=0) w = false;
					}
					if (w) ans++; 
				}
				
			}
		} 
	}
	cout << ans << endl;
	return 0;
}
