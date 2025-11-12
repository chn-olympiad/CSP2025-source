#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
long long z,tepan;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z++;
			a[z]=s[i];
		}
	}
	sort(a,a+z);
	for(long long i=z;i>=0;i--){
		if(a[i]=='0'){
			tepan++;
		}
	}
	if(tepan==z){
		cout<<0;
		return 0;
	}
	for(long long i=z;i>=0;i--){
		if(a[i])cout<<a[i];
	}
	return 0;
}
