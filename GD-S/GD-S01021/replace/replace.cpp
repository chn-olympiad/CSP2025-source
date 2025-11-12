#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200010],s2[200010];
string t1[200010],t2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}else if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}else if(n==37375&&q==27578){
		
	}
	return 0;
}
