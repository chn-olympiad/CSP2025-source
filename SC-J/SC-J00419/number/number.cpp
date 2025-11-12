#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long b=s.size(),a[100010],i=0;
	for(int j=0;j<b;j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[i]=s[j]-'0';
			i++;
		}
	}
	sort(a,a+i);
	for(int j=i-1;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}