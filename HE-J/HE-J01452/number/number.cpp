#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005],f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9') a[++f]=s[i]-'0';
	}
	sort(a+1,a+f+1);
	for(int i=f;i>=1;i--) cout<<a[i];
	
	
	return 0;
}
