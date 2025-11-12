#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int t[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			t[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(t[i]>0){
			cout<<i;t[i]--;
		}
	return 0;
}