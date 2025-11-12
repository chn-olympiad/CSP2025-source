#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,q;
string s1[N],s2[N],t1,t2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int k=1; k<=n; k++) {
		cin>>s1[k]>>s2[k];
	}
	for(int k=1; k<=q; k++) {
		ll l,r;
		cin>>t1>>t2;
		int x=0,ts=t1.size(),ans=0;
		while(t1[x]==t2[x])x++;
		l=x;
		x=ts-1;
		while(t1[x]==t2[x])x--;
		r=x;
		//cout<<l<<' '<<r<<endl;
		for(int o=1; o<=n; o++) {
			int len=s1[o].size();
			if(r-l+1<=len) {
				for(int i=0;i<=l&&i<=ts-len;i++){
					int j=0;
					for(;j<len;j++){
						if(t1[i+j]!=s1[o][j])break;
					} 
					if(j==len&&i<=l&&j-1+i>=r){
						for(j=0;j<len;j++){
							if(t2[i+j]!=s2[o][j])break;
						}
						if(j==len){
							ans++;
							//cout<<s1[o]<<endl;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
