#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long num;
int a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l= s.length();
	
	int ans = 0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1);
	
	int t = 1;
	for(int i=1;i<=ans;i++){
		num+=t*a[i];
		t*=10;
	}
	cout<<num;
	return 0;
}