#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll num[1000005],n=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[++n]=s[i]-'0';
		}
	}
	sort(num+1,num+n+1);
	for(int i=n;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}