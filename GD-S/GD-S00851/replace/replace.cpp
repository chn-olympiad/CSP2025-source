#include <bits/stdc++.h>
using namespace std;

const int maxl = 5e6+100;
char str1[maxl], str2[maxl];

struct node {
	int ch[30];
	bool endm1, endm2, endl;
	int endrcnt=0;
} trie[maxl];
int cnt = 1;
const int root = 1;

inline int nchild(int no, int c) {
	if (!trie[no].ch[c]) {
		cnt++;
		trie[no].ch[c] = cnt;
	}
	return trie[no].ch[c];
}

inline int ldiff(char *s1, char *s2, int len) {
	for (int i=1; i<=len; i++) {
		if (s1[i] != s2[i]) {
//			printf("ldiff=%d\n", i);
			return i;
		}
	}
	return len+1;
}

inline int rdiff(char *s1, char *s2, int len) {
	for (int i=len; i>=1; i--) {
		if (s1[i] != s2[i]) {
//			printf("rdiff=%d\n", i);
			return i;
		}
	}
	return 0;
}

inline void insert(char *s1, char *s2, int len) {
	int ld = ldiff(s1, s2, len),
		rd = rdiff(s1, s2, len);
	
	int no = root;
	
	for (int i=ld; i<=rd; i++) {
		no = nchild(no, s1[i] - 'a');
//		printf("%c", s1[i]);
	}
//	printf("~");
	trie[no].endm1 = true;
	
	for (int i=ld; i<=rd; i++) {
		no = nchild(no, s2[i] - 'a');
//		printf("%c", s2[i]);
	}
//	printf("~");
	trie[no].endm2 = true;
	
	for (int i=ld-1; i>=1; i--) {
		no = nchild(no, s1[i] - 'a');
//		printf("%c", s1[i]);
	}
//	printf("~");
	trie[no].endl = true;
	
	for (int i=rd+1; i<=len; i++) {
		no = nchild(no, s1[i] - 'a');
//		printf("%c", s1[i]);
	}
//	printf("\n");
	trie[no].endrcnt++;
}

inline int search2(int no, char *s, int rs, int len) {
	int ans = 0;
	for (int i=rs; i<=len; i++) {
//		if (trie[no].endr) {
//			putchar('!');
			ans += trie[no].endrcnt;
//		}
		no = trie[no].ch[s[i] - 'a'];
		if (!no) { return ans; }
//		putchar(s[i]);
	}
//	printf("\n");
//	if (trie[no].endr) {
//		putchar('!');
		ans += trie[no].endrcnt;
//	}
	return ans;
}

inline int search1(char *s1, char *s2, int len) {
	int ld = ldiff(s1, s2, len),
		rd = rdiff(s1, s2, len);
		
	int ans = 0;
	int no = root;
	
	for (int i=ld; i<=rd; i++) {
		no = trie[no].ch[s1[i] - 'a'];
		if (!no) { return ans; }
//		putchar(s1[i]);
	}
	if (!trie[no].endm1) {
		return ans;
	}
//	putchar('~');
	
	for (int i=ld; i<=rd; i++) {
		no = trie[no].ch[s2[i] - 'a'];
		if (!no) { return ans; }
//		putchar(s2[i]);
	}
	if (!trie[no].endm2) {
		return ans;
	}
//	putchar('~');
	
	for (int i=ld-1; i>=1; i--) {
		if (trie[no].endl) {
//			printf("!\n\t");
			ans += search2(no, s1, rd+1, len);
//			printf(":");
		}
		no = trie[no].ch[s1[i] - 'a'];
		if (!no) { break; }
//		putchar(s1[i]);
	}
	if (trie[no].endl) {
//		printf("!\n\t");
		ans += search2(no, s1, rd+1, len);
//		printf(":");
	}
	
//	printf("\n");
	
	return ans;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> (str1 + 1) >> (str2 + 1);
		int len = strlen(str1 + 1);
		insert(str1, str2, len);
	}
	
	for (int i=1; i<=q; i++) {
		cin >> (str1 + 1) >> (str2 + 1);
		int len1 = strlen(str1 + 1),
			len2 = strlen(str2 + 1);
			
		if (len1 != len2) {
			cout << "0\n";
			continue;
		}
		
		cout << search1(str1, str2, len1) << '\n';
	}
	
	return 0;
}

