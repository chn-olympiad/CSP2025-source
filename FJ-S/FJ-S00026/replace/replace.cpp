#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	string tmp,tmp1;
	for(int i = 0;i<n;++i){
		cin>>tmp;
		cin>>tmp;
	}
	for(int i = 0;i<q;++i){
		cin>>tmp;
		cin>>tmp1;
		if(tmp==tmp1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
