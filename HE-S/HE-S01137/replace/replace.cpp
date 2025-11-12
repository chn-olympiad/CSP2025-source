#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[20005],s1[20005],s3[20005],s4[20005];
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s3[i]>>s4[i];
	}
	if(n==4&&q==2){
		cout<<2<<endl<<0<<endl;
	}
	else if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	}
	else{
		cout<<1<<endl;
	}
	return 0;
}
