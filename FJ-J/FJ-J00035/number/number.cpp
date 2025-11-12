#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b++;
			a[b]=s[i]-48;
		}
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--) cout<<a[i];
	return 0;
} 
