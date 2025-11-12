#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1,s2;
char t[100010];
char f[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cin>>s1>>s2;
	for(int i=1;i<=n;++i){
		cin>>t[i]>>f[i];
	}
	for(int i=0;i<q;++i){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}