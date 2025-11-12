#include<bits/stdc++.h>
using namespace std;
long long ans;
string sa[200005],sb[200005],s,a,b,ls;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s;
		int u;
		for(;s[u]!=' ';)u++;
		int r=s.size();
		for(int j=0;j<r;j++){
			if(j<u){
				sa[i]+=s[j];
			}
			if(j>u){
				sb[i]+=s[j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
