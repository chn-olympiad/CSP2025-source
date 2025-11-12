#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],tx1,tx2;
map<string,string>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		m[s1[i]]=s2[i];
	}
	for(int i=1;i<=q;i++){
		int o=0;
		cin>>tx1>>tx2;
		if(m[tx1]==tx2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}

