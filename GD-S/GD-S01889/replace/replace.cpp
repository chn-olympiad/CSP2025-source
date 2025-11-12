#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q;
const int N=1e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		ll ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		m=t1.length();
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				for(int k=1;k<=n;k++){
					if(t1.substr(i,j-i+1)==s1[k]){
						if(t2.substr(i,j-i+1)==s2[k]){
							if(t1.substr(0,i)==t2.substr(0,i)&&t1.substr(j+1,m-j-1)==t2.substr(j+1,m-j-1)){
								ans++;
							} 
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
