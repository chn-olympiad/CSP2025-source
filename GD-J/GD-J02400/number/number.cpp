#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
