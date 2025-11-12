#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string s;
int a[1000010];
int t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+1+t,greater<int>());
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
} 
