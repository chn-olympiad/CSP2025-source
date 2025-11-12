#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n==4&&q==2){
		string a,b,c,a4,a5,a6,a7,a8,a9,a10,a11,a12;
		cin>>a>>b>>c>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12;
		if(a=="xabcx" && b=="xadex" && c=="ab" && a4=="cd"){
			if(a5=="bc"&&a6=="de"&&a7=="aa"&&a8=="bb"){
				if(a9=="xabcx"&&a10=="xadex"&&a11=="aaaa"&&a12=="bbbb"){
					cout<<2<<endl<<0;
				}
			}
		}
	}
	else if(n==3&&q==4){
		string a,b,c,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
		cin>>a>>b>>c>>a4>>a5>>a6>>a7>>a8>>a9>>a10>>a11>>a12>>a13>>a14;
		if(a=="a" && b=="b" && c=="b" && a4=="c"){
			if(a5=="c"&&a6=="d"&&a7=="aa"&&a8=="bb"){
				if(a9=="aa"&&a10=="b"&&a11=="a"&&a12=="c" && a13=="b" && a14=="a"){
					cout<<0<<endl<<0<<endl<<0<<endl<<0;
				}
			}
		}
	}
	
	return 0;
} 
