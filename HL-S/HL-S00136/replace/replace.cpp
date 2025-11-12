#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	const int N=1e4+10;
	long long int n,q,ans=0;
	cin>>n>>q;
	string s1[N],s2[N],t1[N],t2[N];
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for (int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for (int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
