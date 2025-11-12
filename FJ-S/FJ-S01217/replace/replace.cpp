#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull P = 13331;

int rd(){
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	int ret = 0;
	while('0' <= c && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}

int n, q;
int len;
char str1[5000002], str2[5000002];
map<ull,int> id;
int idtot;
vector<pair<ull,int> > s1[200002], s2[200002];
vector<ull> t1, t2;

int flag[200002];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n = rd(), q = rd();
	for(int o=1;o<=n;o++){
		char ch = getchar();
		while(ch < 'a' || 'z' < ch) ch = getchar();
		len = 0;
		while('a' <= ch && ch <= 'z') str1[++len] = ch, ch = getchar();
		while(ch < 'a' || 'z' < ch) ch = getchar();
		len = 0;
		while('a' <= ch && ch <= 'z') str2[++len] = ch, ch = getchar();
		//cout << str1 + 1 << ' ' << str2 + 1 << endl;
		//cout << "U" << endl;
		int L = 1, R = 0;
		for(int i=1;i<=len;i++) {
			if(str1[i] != str2[i]) R = i;
		}
		for(int i=len;i>=1;i--){
			if(str1[i] != str2[i]) L = i;
		}
		ull H = 0;
		for(int i=L;i<=R;i++) H = H * P + str1[i] - 'a' + 1;
		for(int i=L;i<=R;i++) H = H * P + str2[i] - 'a' + 1;
		if(id.find(H) == id.end()) id[H] = ++idtot;
		//cout << H << endl;
		
		int ID = id[H];
		H = 0;
		for(int i=L-1;i>=1;i--) H = H * P + str1[i] - 'a' + 1;
		s1[ID].push_back(make_pair(H, o));
		H = 0;
		for(int i=R+1;i<=len;i++) H = H * P + str2[i] - 'a' + 1;
		s2[ID].push_back(make_pair(H, o));
	}
	for(int i=1;i<=idtot;i++){
		sort(s1[i].begin(), s1[i].end());
		sort(s2[i].begin(), s2[i].end());
	}
	
	for(int o=1;o<=q;o++){
		char ch = getchar();
		while(ch < 'a' || 'z' < ch) ch = getchar();
		int len1 = 0;
		while('a' <= ch && ch <= 'z') str1[++len1] = ch, ch = getchar();
		while(ch < 'a' || 'z' < ch) ch = getchar();
		int len2 = 0;
		while('a' <= ch && ch <= 'z') str2[++len2] = ch, ch = getchar();
		if(len1 != len2) {
			printf("0\n");
			continue;
		}
		len = len1;
		//cout << str1 + 1 << ' ' << str2 + 1 << endl;
		int L = 1, R = 0;
		for(int i=1;i<=len;i++) {
			if(str1[i] != str2[i]) R = i;
		}
		for(int i=len;i>=1;i--){
			if(str1[i] != str2[i]) L = i;
		}
		ull H = 0;
		for(int i=L;i<=R;i++) H = H * P + str1[i] - 'a' + 1;
		for(int i=L;i<=R;i++) H = H * P + str2[i] - 'a' + 1;
		//cout << H << endl;
		if(id.find(H) == id.end()){
			printf("0\n");
			continue;
		}
		int ID = id[H];
		H = 0;
		for(int i=L-1;i>=1;i--){
			H = H * P + str1[i] - 'a' + 1;
			t1.push_back(H);
		}
		t1.push_back(0);
		sort(t1.begin(), t1.end());
		
		//for(int i=0;i<t1.size();i++) cout << t1[i] << ' ';
		//cout << endl;
		//for(int i=0;i<s1[ID].size();i++) cout << s1[ID][i].first << ' ';
		//cout << endl;
		
		for(int i=0,j=0;i<t1.size();i++){
			while(j < s1[ID].size() && s1[ID][j].first < t1[i]) j++;
			while(j < s1[ID].size() && s1[ID][j].first == t1[i]) {
				flag[s1[ID][j].second] = o;
				j++;
			}
		}
		H = 0;
		for(int i=R+1;i<=len;i++){
			H = H * P + str2[i] - 'a' + 1;
			t2.push_back(H);
		}
		int cnt = 0;
		t2.push_back(0);
		sort(t2.begin(), t2.end());
		
		//for(int i=0;i<t2.size();i++) cout << t2[i] << ' ';
		//cout << endl;
		//for(int i=0;i<s2[ID].size();i++) cout << s2[ID][i].first << ' ';
		//cout << endl;
		
		for(int i=0,j=0;i<t2.size();i++){
			while(j < s2[ID].size() && s2[ID][j].first < t2[i]) j++;
			while(j < s2[ID].size() && s2[ID][j].first == t2[i]){
				if(flag[s2[ID][j].second] == o){
					cnt++;
				}
				j++;
			}
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}

/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
