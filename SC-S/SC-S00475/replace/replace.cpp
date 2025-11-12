#include<bits/stdc++.h>
using namespace std;
const unsigned long long M = 31;
int n,q;
long long z;
string s[200001][3];
string t[200001][3];
int p[200001];
unsigned long long V[5000001];
unsigned long long e[200001];
bool C(string s1,string s2,string t,int id,int l,int pl){
	string fs = "";
	for(int i = 0;i < l;i = -~i){
		fs += s1[i];
	}
	fs += t;
	for(int i = (l + pl);i < (int)s1.size();i = -~i){
		fs += s1[i];
	}
	return (fs == s2);
}
void f(string s1,string s2,int id){
	int pl = p[id],l = 0,k = 0;
	unsigned long long v = 0;
	for(int i = 0;i < (int)s1.size();i = -~i){
		v = ((v * M) + (s1[i] - 'a' + 1));
		k++;
		if(k < pl){
			continue;
		}
		if(k > pl){
			v -= ((s1[l] - 'a' + 1) * V[k - 1]);
			l++;
			k--;
		}
		if(v == e[id]){	
			z += C(s1,s2,s[id][2],id,l,pl);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	V[0] = 1;
	for(int i = 1;i <= 5e6;i = -~i){
		V[i] = (V[i - 1] * M);
	}
	cin >> n >> q;
	for(int i = 1;i <= n;i = -~i){
		cin >> s[i][1] >> s[i][2];
		p[i] = s[i][1].size();
		for(int j = 0;j < p[i];j = -~j){
			e[i] = ((e[i] * M) + (s[i][1][j] - 'a' + 1));
		}
	}
	for(int i = 1;i <= q;i = -~i){
		cin >> t[i][1] >> t[i][2];
		z = 0;
		for(int j = 1;j <= n;j = -~j){
			f(t[i][1],t[i][2],j);
		}
		cout << z << "\n";
	}
	return 0;
}