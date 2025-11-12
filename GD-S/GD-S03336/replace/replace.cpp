#include<bits/stdc++.h>
using namespace std;
int n,q,posl,posr,opt,ans;
string x,y,l,r,tl,tr;
map<pair<string,string>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[{x,y}]++;
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		if(l.size()!=r.size()){
			cout<<"0\n";
			continue;
		}
		opt=0;
		for(int j=0;j<l.size();j++){
			if(l[j]!=r[j]){
				if(opt==0){
					posl=j;
					opt=1;
				}
				posr=j;
			}
		}
		ans=0;
		for(int j=0;j<=posl;j++){
			for(int k=posr;k<l.size();k++){
				tl=l.substr(j,k-j+1);
				tr=r.substr(j,k-j+1);
				ans+=mp[{tl,tr}];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
