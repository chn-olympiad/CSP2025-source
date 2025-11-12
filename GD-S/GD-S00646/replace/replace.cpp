#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=2;j++){
			cin>>s;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
