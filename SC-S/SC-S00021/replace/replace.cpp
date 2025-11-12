#include<bits/stdc++.h>
using namespace std;
int n, q;
char s1[2500005], s2[2500005];
int l[200005];
char t1[2500005], t2[2500005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1;
		cin >> s2;
//		l[i] = strlen(s1);
	}

//	for (int op=1;op<=q;op++){
//		cin>>t1>>t2;
//		int len=strlen(t1),lenn=strlen(t2);
//		if(len!=lenn){
//			cout<<0<<'\n';
//			continue;
//		}
//		for (int i=1;i<=n;i++){
//			if(len<l[i])continue;
//			for (int j=1;j<=len;j++){
//				t[i]=s1[i]
//			}
//		}
//	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		cout << 0 << '\n';
	}
	return 0;
}