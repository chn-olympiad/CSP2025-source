#include<bits/stdc++.h>
using namespace std;
int a[1000010],aa=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);	
	int i=0;
	string s,s1;
	cin>>s;
	while(s!=s1){
		if(s[i]>='0'&&s[i]<='9'){
			a[aa]=s[i]-'0';
			aa++;
		}
		s1+=s[i];
		i++;
	}
	sort(a,a+aa);
	for(;aa>0;aa--){
		cout<<a[aa-1];
	}
	return 0;
}
