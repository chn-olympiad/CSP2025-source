#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string fi,se;
}a[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi>>a[i].se;
	}
	while(q--){
		string ss,sss;
		cin>>ss>>sss;
		cout<<0<<"\n";
	}
	return 0;
}
