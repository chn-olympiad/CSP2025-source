#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],len1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>=48 && s[i]<=57){
    		a[i]=s[i]-48;
    		len1++;
		}
	}
	sort(a,a+s.size()-1);
	for(int i=len1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
