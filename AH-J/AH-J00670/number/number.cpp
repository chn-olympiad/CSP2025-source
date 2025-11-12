#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans,l;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++ans]=int(s[i]-'0');
		}
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--) cout<<a[i];
	return 0;
}
