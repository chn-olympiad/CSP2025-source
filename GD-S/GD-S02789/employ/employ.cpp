#include <bits/stdc++.h>
using namespace std;
long long n,m,c[510],ans;
string s;
bool cmp(int x,int y){
	return x<=y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(int(s[i])==1){
				ans++;
			}
		}
		cout<<ans%998244353;
	}
	if(m==n){
		cout<<m;
	}
	return 0;
}
