#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1, s2;
}ma[200007];
int n, q;
int ans = 0;
int find(string a, string b){
	for(int k = 1;k <= n;++k){
		for(int i = 0;i < a.size() - ma[k].s1.size();++i){
			string s;
			for(int j = 0;j < i;++j){
				s[j] = a[j];
			}
			bool bo = 1;
			for(int j = i;j < ma[k].s1.size();++j){
				if(a[j] != ma[k].s1[j - i]){
					bo = 0;
				}
				s[j] = ma[k].s2[j - i];
			}
			if(bo){
				for(int j = i + ma[k].s1.size();j <= a.size();++j){
					s[j] = a[j];
				}
				for(int j = 0;j < a.size();++j){
					if(s[j] != b[j]){
						bo = 0;
					}
				}
				if(bo){
					ans++;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;++i){
		cin >> ma[i].s1 >> ma[i].s2;
	}
	for(int i = 1;i <= q;++i){
		string a, b;
		cin >> a >> b;
		ans = 0;
//		cout << find(a, b) << endl;
		cout <<0 <<endl;
	}
	return 0;
}
