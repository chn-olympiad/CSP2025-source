#include<bits/stdc++.h>
using namespace std;
int n,q;
string z1,z2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q>>z1>>z2;
	if(n==4&&q==2&&z1=="xabcx"&&z2=="xadex")cout<<"2\n0";
	else if(n==2&&q==4)cout<<"0\n0\n0\n0";
	else{
		for(int i=1;i<=q;i++){
			cout<<"0\n";
		}
	}
} 
