#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin >>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		cin >>s1>>s2;
		if(s1!=s2)
		{
			cout <<2<<endl;
		}else{
			cout <<0<<endl;
		}
	}
	return 0;
}
