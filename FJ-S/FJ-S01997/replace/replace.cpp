#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string t1,t2,inp[200005],s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string u,v;
		getline(cin,u);
		getline(cin,v);
		inp[i]=u,s[i]=v;
	}
	while(q--){
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				for(int k=1;k<=n;k++){
					if(i==0&&j==t1.size()-1){
						if(t1.substr(i,j)==inp[k]&&s[k]==t2){
							ans++;
						}
					}
					else if(i==0){
						if(t1.substr(i,j)==inp[k]&&s[k]+t1.substr(j+1,t1.size()-1)==t2){
							ans++;
						}
					}
					else if(j==t1.size()-1){
						if(t1.substr(i,j)==inp[k]&&t1.substr(0,i-1)+s[k]==t2){
							ans++;
						}
					}
					else{
						if(t1.substr(i,j)==inp[k]&&t1.substr(0,i-1)+s[k]+t1.substr(j+1,t1.size()-1)==t2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
