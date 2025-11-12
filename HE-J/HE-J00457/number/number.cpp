#include<bits/stdc++.h>
using namespace std;
string s;
long long ans[1000005],x=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			ans[x++]=s[i]-'0';
		}
	} 
	sort(ans,ans+x,cmp);
	for(long long i=0;i<x;i++) cout<<ans[i];
	return 0;
} 
