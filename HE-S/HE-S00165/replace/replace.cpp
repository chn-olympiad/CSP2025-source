#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int N=2e5+7;
string s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string a,b;
	int n,q,i,j,x,y,ans,f,d,cnt;
	cin>>n>>q;
	for(i=0;i<n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		f=0;d=1;
		for(i=0;i<n;i++){
			for(j=0;j<a.size();j++){
				if(d&&(a.substr(j,s[i].size())==s[i]&&b.substr(j,t[i].size())==t[i])){
					cnt++;d=0;f=1;
					j+=s[i].size()-1;
				}
				else if(a.substr(j,s[i].size())==b.substr(j,t[i].size())){}
				else{
					f=0;
					break;
				}
			}
			if(f==1) ans+=cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
