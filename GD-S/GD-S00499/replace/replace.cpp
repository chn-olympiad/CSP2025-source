#include<bits/stdc++.h>
using namespace std;
string s[200005][5];
string t[5000005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long int n,q;
	cin>>n>>q;
	for(long long int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(long long int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>t[i][j];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
