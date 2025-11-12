#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+10;
long long a[15];
void solve(){
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0') a[0]++;
		if(s[i]=='1') a[1]++;
		if(s[i]=='2') a[2]++;
		if(s[i]=='3') a[3]++;
		if(s[i]=='4') a[4]++;
		if(s[i]=='5') a[5]++;
		if(s[i]=='6') a[6]++;
		if(s[i]=='7') a[7]++;
		if(s[i]=='8') a[8]++;
		if(s[i]=='9') a[9]++;
	}
	for(long long i=9;i>=0;i--){
		if(a[i]>0){
			while(a[i]>0){
				a[i]--;
				cout<<i;
			}
		}
	}
	return;	
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long T=1;
	//cin>>T
	while(T--){
		solve();
	}
	return 0;
}
