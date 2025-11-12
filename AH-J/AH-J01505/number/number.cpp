#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],m,n;
int main(){
	 freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
	cin>>s;
	m=s.size();
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	if(a[n]){
		for(int i=n;i>=1;i--) cout<<a[i];
	}
	else cout<<0;
	return 0;
}
