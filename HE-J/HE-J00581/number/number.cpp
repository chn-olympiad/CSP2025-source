#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000000],j=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(s[i]-'0');
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
