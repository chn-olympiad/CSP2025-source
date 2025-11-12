#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,g;
int ans[10000001];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(LL i=0;i<n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			ans[g]=-(a[i]-'0');
			g++;
		}
	}
	sort(ans,ans+g);
	for(LL i=0;i<g;i++){
		cout<<-ans[i];
	}
	return 0;
}
