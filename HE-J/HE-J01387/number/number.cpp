#include <bits/stdc++.h>
using namespace std;
int const N=1e6+5;
string s;
int a[N],ans=0;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int l=s.size();
	int k=0;
	for(int i=0;i<l;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	int p=1;
	for(int i=1;i<=k;i++) {
		ans+=a[i]*p;
		p*=10;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
