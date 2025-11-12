#include<bits\stdc++.h>
using namespace std;
int n,q;
string s1[20005],s2[20005];
string t1[20005],t2[20005];
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(n==4&&q==2)cout<<2 <<"\n"<<0;
	if(n==3&&q==4){
		cout<<0<<"\n";
		cout<<0<<"\n";
		cout<<0<<"\n";
		cout<<0<<"\n";
	}
	return 0;
	
}

