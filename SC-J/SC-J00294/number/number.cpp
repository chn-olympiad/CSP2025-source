#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string a;cin>>a;vector<int> num;
	f(i,0,a.size()-1){
		if(a[i]>='0'&&a[i]<='9')num.push_back(a[i]-'0');
	} sort(num.begin(),num.end(),greater<>());
	for(int u:num){
		cout<<u;
	}
}