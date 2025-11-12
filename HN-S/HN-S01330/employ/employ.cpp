#include<bits/stdc++.h>
using namespace std;
int n,m,c[500];
string s;
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flag=0;
		}
	}
	if(flag){
		cout<<m;
	}else cout<<n;
	return 0;
}

