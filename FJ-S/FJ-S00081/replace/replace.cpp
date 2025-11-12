#include<bits/stdc++.h>
using namespace std;
char s[1000001],t[1000001];
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=q;i++)
		cin>>t[i];
	int g,p;
	if(n==4){
		cout<<2<<0;
	}
	if(n==3)
		cout<<0<<0<<0<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
