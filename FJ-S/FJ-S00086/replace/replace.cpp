#include<bits/stdc++.h>
using namespace std;
long long n,q,ans=0,o=0;
string s[300005][2],t,r,a,b,c;
bool za(long long x,long long y){
	bool b=1;
	for(int i=1;i<=n;i++){
    	int p=0;
    	if(s[i][0].size()>=y){
    		for(int j=x;j<x+s[i][0].size();j++){
			if(s[i][0][p]!=r[j]||s[i][1][p]!=t[j]){
				b=0;
				break;
			}
			p++;
		}
		if(b==1){
			return 1;
		}
		b=1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(long long i=1;i<=q;i++){
		cin>>r>>t;
		ans=0;
		if(r.size()!=t.size()){
			cout<<0<<endl;
		}else{
			o=0;
			for(long long j=0;j<r.size();j++){
				if(r[j]!=t[j]){
					o++;
				}
			}
			for(long long j=0;j<r.size();j++){
				if(za(j,o)==1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		if(i==q){
			return 0;
		}
	}
	return 0;
}
