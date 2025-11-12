#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int f[N];

bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);


	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	cin>>s;
	int n = s.length();
	long long cnt = 1;

	for(int i=0; i<n; i++) {
		if(s[i]>='0' && s[i]<='9') {
			f[i] = s[i] - '0';
			cnt++;
		} else {
			continue;
        }
	}

	sort(f,f+cnt,cmp);

	for(int i=0; i<cnt-1; i++)
		cout<<f[i];
	return 0;
}
