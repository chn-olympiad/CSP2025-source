#include<bits/stdc++.h> 
using namespace std;
const int maxn=1e6+5;
char s[maxn];
vector<int> num;
bool is_num(char c) {
	if (c>='0'&&c<='9') return true;
	return false;
} 
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s;
	int l=strlen(s);
	for (int i=0;i<l;i++) {
		if (is_num(s[i])) {
			int t=s[i]-'0';
			num.push_back(t);
		}
	}
	sort(num.begin(),num.end(),cmp);
	int k=num.size();
	int pos=0;
	while (num[pos]==0&&pos<k-1) {
		pos++;
	}
	for (int i=pos;i<k;i++) {
		cout<<num[i];
	}
	cout<<'\n';
	return 0;
}    
