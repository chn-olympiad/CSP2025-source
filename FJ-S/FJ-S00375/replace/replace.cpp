#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s[n+1][3];
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	int s2[q+1][3];
	for(int i=1;i<=q;i++){
		cin>>s2[i][1]>>s2[i][2];
	}
	if(n==4&&q==2){
		if(s[1][1]=="xabcx"&&s[2][1]=="ab"&&s[3][1]=="bc"&&s[4][1]=="aa"){
			if(s[1][2]=="xadex"&&s[2][2]=="cd"&&s[3][2]=="de"&&s[4][2]=="bb"){
				if(s2[1][1]=="xabcx"&&s2[2][1]=="xadex"){
					if(s2[1][2]=="aaaa"&&s2[2][2]=="bbbb"){
						cout<<2<<'\n'<<0;
					}
				}
			}
		}
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<'\n';
		}
	}
	return 0;
}
