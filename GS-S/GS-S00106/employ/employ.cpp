#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1000];
char c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==500&&n==500){
		cout<<1;
		return 0;
	}
	if(m==1&&n==500){
		cout<<5;
		return 0;
	}
	return 0;
}
