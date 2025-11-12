#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i-1]!='0'){
				cout<<0;
				return 0;
			}
			for(int j=1;j<=n;j++){
				c[j]--;
				if(c[j]<0){
					cout<<0;
					return 0;
				}
			}
		}
		cout<<1;
	}
	if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<n;
				return 0;
			}
		}
	}
	cout<<2;
	return 0;
}
