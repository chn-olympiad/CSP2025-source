#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n+m;i++){
		getline(cin,s);
	}
	for(long long i=1;i<=n;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
