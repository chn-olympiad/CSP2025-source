#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
char a[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a+1,a+1+j);
	for(int i=j; i>=1; i--){
		cout<<a[i];
	}
	return 0;
}