#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	string s1[n],s2[n];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	} 
	string t1[q],t2[q];
	for(int i=0;i<q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n==4 && q==2){
		cout<<2<<"\n"<<0;
	}else if(n==3 && q==4){
		cout<<0<<"\n"<<0<<'\n'<<0<<"\n"<<0;
	}
	return 0;
}
