#include<bits/stdc++.h>
using namespace std;
string s;
long long num[100005],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(long long i=0;i<s.size();++i){
		if('0'<=s[i] && '9'>=s[i]){
			j++;
			num[j]=s[i]-'0';
		}
	}
	sort(num+1,num+j+1);
	for(long long i=j;i>=1;--i){
		cout<<num[i];
	}
	return 0;
}