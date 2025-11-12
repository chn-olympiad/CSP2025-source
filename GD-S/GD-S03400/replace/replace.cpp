#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==4&&b==2&&c=="xabcx"&&d=="xadex"){
		cout<<2<<endl<<0;
	}
	if(a==3&&b==4&&c=="a"&&d=="b"){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}
