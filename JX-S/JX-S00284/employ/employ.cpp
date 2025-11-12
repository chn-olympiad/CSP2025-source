#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
bool f=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]!='1') f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f){
		double cnt;
		for(int i=1;i<=m&&n;i++){
			cnt*=n;
			n--;
		}
		for(int i=m;i>=1;i--){
			cnt/=m;
		}
		cout<<cnt;
	}
	else cout<<n;
	return 0;
}
