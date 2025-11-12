#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
string s;
int ans[N],sum=0;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			ans[sum]=(int)(s[i]-'0');
		}
	}
	sort(ans+1,ans+1+sum,cmp);
	for(int i=1;i<=sum;i++){
		cout<<ans[i];
	}
	return 0;
}
