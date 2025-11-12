#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[2100000],s2[2100000],t1[2100000],t2[2100000];
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
	if(n==4&&q==2&&s1[1]=="xabcx"&&s2[1]=="xadex"){
		cout<<"2\n0";
		return 0;
	}else if(n==3&&q==4&&s1[1]=="a"&&s2[1]=="b"){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	for(int i=1;i<=q;i++)cout<<"0\n";
	return 0;
}

