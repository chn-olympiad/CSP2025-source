#include "bits/stdc++.h"
using namespace std;
string a;
long long b[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9') b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--) while(b[i]--) cout<<i;
	return 0;
}
