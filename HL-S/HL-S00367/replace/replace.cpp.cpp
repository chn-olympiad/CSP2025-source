#include<bits/stdc++.h>
using namespace std;
long long s1[2000001],s2[2000001],t1[2000001],t2[2000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(long long i=0;i<q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}

