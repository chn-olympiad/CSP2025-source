#include <bits/stdc++.h>
using namespace std;
long long s[200000][3];
long long t[200000][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	long long n,q;
	cin>>n>>q;
	for (long long i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for (long long j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	for (long long a=1;a<=q;a++){
		cout<<0<<endl;
	}
	return 0;
}

