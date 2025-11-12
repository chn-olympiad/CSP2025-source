#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	f=1;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[f++]=s[i]-'0';
		}
	}
	f--;
	sort(a+1,a+1+f);
	for(int i=f;i;i--)cout<<a[i];
	return 0;
}
