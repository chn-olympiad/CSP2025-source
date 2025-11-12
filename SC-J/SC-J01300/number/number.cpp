#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i])-48>=0 && int(s[i])-48<=9){
			a[ans]=int(s[i])-48;
			ans++;
		}
	}
	sort(a,a+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}