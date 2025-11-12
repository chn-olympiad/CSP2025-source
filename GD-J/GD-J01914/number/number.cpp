#include<bits/stdc++.h>
#define ll long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=44;
string s;
ll cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if(isdigit(s[i]))cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(cnt[i]--)cout<<i;
	}
	return 0;
} 
