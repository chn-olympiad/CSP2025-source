#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld a[110],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	lld n=s.size();
	for(int i=0;i<=n;i++){
		int x=int(s[i]-'0');
		if((x>=0)&&(x<=9)){
			a[x]++;ans++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}