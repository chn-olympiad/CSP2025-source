#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10; 
string s;
int a[N],l;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++l]=s[i]-'0';
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--) cout<<a[i];
	return 0;
} 
/*
#Shang4Shan3Ruo6Shui4
*/
