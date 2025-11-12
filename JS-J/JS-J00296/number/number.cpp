#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define PII <int,int>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
ll n,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll i=1;
	while(s[i]==' '){
		if(isdigit(s[i])){
			a[i]=int(s[i]);
			n++;
		}i++;
	}
	sort(a+1,a+n+1);
	cout<<s;
	for(int j=n;j>=1;j--) cout<<a[j];
	return 0;
}
