#include<bits/stdc++.h>
using namespace std;
struct ppair{
	string s1,s2;
}s[200000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		int c=0;
		string x,y; cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int p=x.find(s[i].s1);p!=-1;p=x.find(s[i].s1,p+1)){
				//int p=x.find(s[i].s1);
				string ss=x.substr(0,p)+s[i].s2+x.substr(p+s[i].s2.size(),x.size()-1);
				//cout<<ss<<endl;
				if(ss==y)c++;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
