#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+34;
bool Mbe;
int n,q;
string s[N][3],t[N][3];
string s1,s2;

int nxt[N];
int la,lb,l2;
void getnext(string str, string mat){
	int j = 0;
	for (int i =0;i<=lb;i++) nxt[i]=0;
	 
	for (int i = 2; i <= lb;i++){
		while (j && mat[i] != str[j+1]) j = nxt[j];
		if (mat[i] == str[j+1]) j++;
		nxt[i]=j;
	}
}

// kmp判是否是字串 
int kmp(string str, string mat){
	int j = 0;
	for (int i = 1; i <= la;i++){
		while (j && mat[j+1] != str[i]) j =nxt[j];
		if (mat[j+1] == str[i]) j++;
		if (j == lb){
			return (i-lb+1);
		}
	}
	return -1;
}

bool Med;
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
//	freopen("C:\\Users\\Administrator\\Desktop\\题目\\replace\\replace2.in","r",stdin); 
//	freopen("out.txt","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cerr << "Mem: " << double(&Mbe-&Med) / 1048576.0 << "MB\n";

	cin >> n >> q;
	for (int i = 1; i <= n;i++){
		cin >> s[i][1] >> s[i][2];	
		s[i][1] = ' '+s[i][1] ;
		s[i][2] = ' '+s[i][2] ; 
	}
//	for (int i = 1; i <= q;i++){
//		cin >> t[i][1] >> t[i][2];
//		t[i][1] = ' '+t[i][1] ;
//		t[i][2] = ' '+t[i][2] ;
//	}

	
	while (q--){
		cin >> s1 >> s2;
		s1 =' ' + s1;
		s2 =' ' + s2;
		la= s1.size()-1;
		int ans = 0;

		for (int i = 1; i <= n;i++){
			lb=s[i][1].size()-1;
			l2 = s[i][2].size()-1;
			getnext(s1,s[i][1]);
			int pos = kmp(s1,s[i][1]);
			if (pos != -1){ // 是子串
				string tmp=s1;
				for (int j = pos;j <= pos+l2-1; j++){
					tmp[j] = s[i][2][j-pos+1];
				}
				if (tmp == s2) ans++;
			}
		}
		cout << ans << '\n';
	}

	
//	cerr << "Time: " << double(clock()*1.0 / CLOCKS_PER_SEC)<<'\n';
	return 0;
}

