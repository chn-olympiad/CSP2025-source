#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N],top;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++top]=s[i]-48;
		}
	}
	sort(a+1,a+top+1);
	if(a[top]==0) cout<<0;
	else{
		for(int i=top;i>=1;i--)cout<<a[i];
	}	
	return 0;
}
