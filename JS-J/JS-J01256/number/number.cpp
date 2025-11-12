#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000002],ind = 0;
	int p = s.length();
	for(int i = 0;i<p;i++){
		if(s[i] >='0' && s[i]<='9'){
			a[ind] = s[i]-'0';
			ind++;
		}
	}
	sort(a,a+ind);
	for(int i = ind-1;i>=0;i--) cout<<a[i];
	return 0;
}
