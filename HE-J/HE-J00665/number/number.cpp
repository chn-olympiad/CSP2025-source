#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a[100010],i;
	cin>>s;
	for(i=1;i<=s.len;i++){
		if(s.len<='9' && s.len>='0') {
			a[i]=s.len;
		}
		sort(a,a+1);
	}
	cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
