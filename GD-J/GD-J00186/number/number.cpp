#include <bits/stdc++.h>
using namespace std;

bool cmp (int x,int y) {
	return x>y;
}

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	string s; 
	cin>>s;
	
	int n[100005],k=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]>='0' && s[i]<='9') {
			n[k++]=int(s[i]-'0');
		}
	}
	
	sort(n,n+k,cmp);
	
	for (int i=0;i<k;i++) {
		cout<<n[i];
	}
	return 0;
}
