#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000100];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len = s.length(),x = 0;
	for(int i = 0;i < len;i++){
		if(s[i]<='9' && s[i]>='0'){
			a[x] = s[i]-48;
			x++;
		}
	}
	sort(a,a+x);
	for(int i = x-1;i >= 0;i--) cout<<a[i];
	return 0;
}
