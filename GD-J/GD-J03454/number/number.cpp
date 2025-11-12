#include<bits/stdc++.h>
using namespace std;
long long a[1000001],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j=j+1;
		}
	}
	sort(a,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
