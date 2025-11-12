#include<bits/stdc++.h>
using namespace std;
const int n=1e6+3;
long long a[n];
long long t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 