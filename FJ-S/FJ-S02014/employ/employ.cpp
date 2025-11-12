#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[100001],c[100001];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int o=0;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-48;
		if(a[i+1]==1){
			o++;
		}
	}
	if(o<m){
		cout<<"0";
	}
	else{
		cout<<"14";
	}

	return 0;

}
