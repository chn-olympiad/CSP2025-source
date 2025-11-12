#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[100000];
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	int t=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t);
	for(int i=t-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
