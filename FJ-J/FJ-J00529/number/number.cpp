#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int cnt=0;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i;i--){
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}

