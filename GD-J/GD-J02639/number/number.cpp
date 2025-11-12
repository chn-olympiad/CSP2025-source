#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NN=1e6+10;
int a[NN];
int l=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') {
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a+1,a+l);
	for(int i=l-1;i>0;i--) cout<<a[i];
	return 0;
} 
