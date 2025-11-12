#include<bits/stdc++.h>
#define int long long
using namespace std;
string a;
int cnt[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9')
		cnt[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}
