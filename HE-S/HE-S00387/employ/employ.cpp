#include <bits/stdc++.h>
using namespace std;
char s[510],c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	if(m==n){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1'){
			sum++;	
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}for(int i=1;i<=n;i++){
		if(c[i]=='0' && s[i]=='1'){
			sum--;
		}
	}
	cout<<sum;
	return 0;
}
