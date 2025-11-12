#include<bits/stdc++.h>
using namespace std;
string s;
int n,num[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9') num[(int)(s[i]-'0')]++;
	int e=0;
	for(int i=1;i<=9;i++)
		if(num[i]) e=1;
	if(!e){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
