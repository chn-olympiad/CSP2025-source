#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<(ll)s.size();i++)if(s[i]<'0'||s[i]>'9')s[i]=0;
	sort(s.begin(),s.end());
	while(s[0]==' ')s.erase(0,1);
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
}
