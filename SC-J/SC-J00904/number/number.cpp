#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
string s;
long long n,ans[N],cnt=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57){
			cnt++;
			ans[cnt]=int(s[i])-48;
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<ans[i];
	} 
	return 0;
}