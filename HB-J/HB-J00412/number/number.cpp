#include<bits/stdc++.h>
using namespace std;
int a[114514];
#define int long long
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int d = 0;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			d++;
			a[d] = s[i]-'0';
		}
	}
	sort(a+1,a+1+d);
	for(int i=d;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
