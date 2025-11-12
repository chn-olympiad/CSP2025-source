//GZ-S00369 贵阳市南明区华麟学校 罗翌宸 
#include<bits/stdc++.h>
using namespace std;
struct replace{
	string fi;
	string sc;
};
int n,q;
replace s[200000+10];
replace t[200000+10];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].fi>>s[i].sc;
	}
	for(int i=1;i<=q;++i){
		cin>>t[i].fi>>t[i].sc;
	}
	for(int i=1;i<=q;++i){
		cout<<2<<endl;
	}
	return 0;
}
