#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<+len;++i){
		if(s[i]>='0'&&s[i]<='9') a[++c]=s[i]-'0';
	}
	sort(a+1,a+1+c,greater<int>());
	for(int i=1;i<=c;++i) cout<<a[i];
    return 0;
}
