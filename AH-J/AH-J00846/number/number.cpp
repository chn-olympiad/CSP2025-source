#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') a[++ans]=1;
		if(s[i]=='2') a[++ans]=2;
		if(s[i]=='3') a[++ans]=3;
		if(s[i]=='4') a[++ans]=4;
		if(s[i]=='5') a[++ans]=5;
		if(s[i]=='6') a[++ans]=6;
		if(s[i]=='7') a[++ans]=7;
		if(s[i]=='8') a[++ans]=8;
		if(s[i]=='9') a[++ans]=9;
		if(s[i]=='0') a[++ans]=0;
	}
	sort(a+1,a+1+ans);
	for(int i=ans;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
