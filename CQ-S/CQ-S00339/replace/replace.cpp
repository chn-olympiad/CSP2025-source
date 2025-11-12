#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+5,mod=1e9+7;
ll n,q,m,m2,l,sum;
string s1[N],s2[N],t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		sum=0;
		for(ll i=1;i<=n;i++){
			m=s1[i].size();
			m2=t1.size();
			for(ll j=m-1;j<m2;j++){
				if(t1.substr(j-m+1,m)==s1[i]){
					if(t1.substr(0,j-m+1)+s2[i]+t1.substr(j+1,m2-j-1)==t2)sum++;
				}
			}
		}
		cout<<sum<<'\n';
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

*/
