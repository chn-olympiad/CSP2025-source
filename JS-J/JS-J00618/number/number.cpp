#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	string ans="";
	cin>>a;
	int i=0;
	while(a[i]!='\0'){
		if(a[i]>='0' && a[i]<='9'){
			ans+=a[i];
		}
		i++;
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	
		cout<<ans;
	
	return 0;
}
