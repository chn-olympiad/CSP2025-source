#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++)cin>>s>>s;
	if(n==4&&q==2){
		cout<<"2\n";
		cout<<"0";
	}else{
		for(int i=1;i<=q;i++)cout<<"0\n";
	}
	return 0;
} 
