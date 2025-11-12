#include<bits/stdc++.h>
using namespace std;
long long a[1000005],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	long long len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
			cout<<a[i];
	}
	return 0;
}
