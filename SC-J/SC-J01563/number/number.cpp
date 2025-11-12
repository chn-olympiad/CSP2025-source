#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
string s;
int a[maxn],tot;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++tot]=s[i]-48;
	sort(a+1,a+1+tot,greater<int>());
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=tot;i++)cout<<a[i];
	return 0;
}