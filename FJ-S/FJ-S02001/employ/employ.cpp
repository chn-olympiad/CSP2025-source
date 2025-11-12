#include<bits/stdc++.h>
using namespace std;
int n,m,j12=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("empioy.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int a[500];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			j12++;
		}
	}
	if(j12<m){
		cout<<0;
		return 0;
	}
	return 0;
}
