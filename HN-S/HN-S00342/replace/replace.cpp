#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans=0;
bool check(string t1,string t2){
	if(t1.size()!=t2.size())return false;
	for(int i=0;i<t1.size();i++)
		if(t1[i]!=t2[i])
			return false;
	return true;
}
string x[N],y[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.size();j++){
				string x1,x2,x3;
				x1=t1.substr(0,j),x2=t1.substr(j,x[i].size()),x3=t1.substr(j+x[i].size());
				string tx=x1+x2+x3;
				if(check(tx,t2))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
