#include<iostream>
#include<string>
using namespace std;

string s;

int cnt[20];

signed main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s;
	for(auto c:s)if(isdigit(c))++cnt[c^48];
	for(int i=9;~i;--i)if(cnt[i])for(int j=1;j<=cnt[i];++j)cout<<i;
	return cout<<"\n",0;
}