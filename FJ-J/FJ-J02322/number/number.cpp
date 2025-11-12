#include<vector>
#include<algorithm>
#include<iostream>
#define int unsigned long long
using namespace std;
inline bool cmp(int a,int b){
	return a>b;
}
int ans,n,i;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	vector<int>a;
	for(i=0;i<n;++i)
	 if(isdigit(s[i]))a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),cmp);
	for(i=0;i<a.size();++i)
	 ans*=10,ans+=a[i];
	cout<<ans;
	return 0;
}
