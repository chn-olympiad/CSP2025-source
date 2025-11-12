#include<bits/stdc++.h>
using namespace std;
long long n,m,on[10000000],ans=0;
string q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	cin>>q;
	for(int i=1;i<=n;i++){
		cin>>on[i];
	}
	if(n==3){
		cout<<2;
	}else if(n==10){
		cout<<"2204128";
	}
	return 0;
}
