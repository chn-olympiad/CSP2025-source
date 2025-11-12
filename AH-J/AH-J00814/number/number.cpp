#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<(int)s.size();i++) 
		if(s[i]>='0'&&s[i]<='9') 
			a[s[i]-'0']++;
	for(int i=9;i>=0;i--) 
		while(a[i]!=0) {
			cout<<i;
			a[i]--;
		}
	cout<<endl;
	return 0;
}
