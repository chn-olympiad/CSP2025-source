#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9' && s[i]>='0') a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,greater<long long>());
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
