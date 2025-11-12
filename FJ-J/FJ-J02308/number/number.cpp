#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
	    a[num++]=s[i];
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		if(a[i]>=48&&a[i]<=57) cout<<a[i]-48;
	}
	return 0;
}
