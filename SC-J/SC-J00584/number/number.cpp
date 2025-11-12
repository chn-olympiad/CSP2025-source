#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string s;
int a[2000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int w=0;
	int c=0;
	int n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++w]=s[i]-'0';
			c++;
		}
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}
	return 0;
}