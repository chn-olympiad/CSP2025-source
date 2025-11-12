#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,L = 5e6 + 5;
int n,q,l,r,p1[L + L],p2[L + L],ans;
char s[L];
vector <string> s1,s2;
string t1,t2;
string read(){
	scanf("%s",s);
	string res = "\0";
	for(int i = 0; i < strlen(s); i++){
		res = res + " ";
		res[i] = s[i];
	}
	return res;
}
void kmp(int l,string s,int p[]){
	for(int i = 1; i < l; i++){
		int j = p[i - 1];
		while(s[j] != s[i] && j > 0) j = p[j - 1];
		if(s[j] == s[i]) ++j;
		p[i] = j;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 0; i < n; i++) s1.push_back(read()),s2.push_back(read());
	for(int i = 0; i < q; i++){
		t1 = read(),t2 = read();
		if(t1.size() != t2.size()){
			printf("0\n");
			continue;
		}
		l = 0,ans = 0;
		while(t1[l] == t2[l] && l < n) ++l;
		r = l;
		for(int j = l; j < n; j++){
			if(t1[j] != t2[j]) r = j;
		}
		for(int j = 0; j < n; j++){
			if(s1.size() < r - l + 1) continue;
			kmp(s1[j].size() + t1.size() + 1,s1[j] + "#" + t1,p1);
			kmp(s2[j].size() + t2.size() + 1,s2[j] + "#" + t2,p2);
			for(int k = r + s1[j].size() + 1; k < min(l + (s1[j].size() << 1) + 1,t2.size() + s2[j].size() + 1); k++){
				if(p1[k] == s1[j].size() && p2[k] == s2[j].size()) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
