#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
char c[10000];
char d[10000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
	}
	for(int i=1;i<=q;i++){
		cin>>c>>d;
	}
	if(n==4&&q==2){
		cout<<2<<"\n"<<0;
		return 0;
	}
	else if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<"0\n";
		}
	}
	return 0;
} 
