#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ans[1000005];
int an;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')ans[++an]=s[i];
	}
	sort(ans+1,ans+an+1);
	for(int i=an;i>=1;i--)cout<<ans[i];
	return 0;
}
