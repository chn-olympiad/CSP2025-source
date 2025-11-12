#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[2010][2010],s2[2010][2010],t1[2010],t2[2010],t3[2010];
vector<int> findpos(char* t,char* s) {
	vector<int> ret;
	int st = strlen(t),ss = strlen(s);
	string buf;
	for (int i = 0; i < ss; i++) buf += t[i];
	for (int i = ss; i < st; i++) {
		if (buf == s) ret.push_back(i-ss);
		if (i != st - 1) {
			buf.erase(buf.begin());
			buf += t[i+1];
		}
	}
	return ret;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 0; i < n; i++) {
		scanf("%s%s",s1[i],s2[i]);
	}
	while (q--) {
		scanf("%s%s",t1,t2);
		int ret = 0;
		strcpy(t3,t1);
		for (int i = 0; i < n; i++) {
			int l = strlen(s1[i]);
			vector<int> pos = findpos(t1,s1[i]);
			for (int j = 0; j < pos.size(); j++) {
				for (int k = pos[j]; k < pos[j]+l; k++) {
					t3[k] = s2[i][k-pos[j]];
				}
//				cout << t3 << " " << t2 << endl;
				if (strcmp(t3,t2) == 0) {
					ret++;
					strcpy(t3,t1);
					break;
				}
				strcpy(t3,t1);
			}
		}
		printf("%d\n",ret);
	}
}
