#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+2;
string s,c = "";
int l = 0,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++l] = s[i]-'0';
	}
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--)c+=char(a[i]+'0');
	cout<<c;
	return 0;
}


