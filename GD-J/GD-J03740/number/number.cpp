#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
vector<int> ilist;
bool cp(int a,int b){
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') ilist.push_back(s[i]-'0');
	}
	sort(ilist.begin(),ilist.end(),cp);
	for (int i = 0; i < ilist.size(); i++) {
		printf("%d",ilist[i]);
	}
	printf("\n");
}
