//GZ-S00389 北京师范大学贵阳附属中学 葛森蓥

#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<string,string>m;
ll n,q,l,r,ans;
string s1,s2,x,y,z;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(ll a=0;a<n;a++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		l=0;
		while(s1[l]==s2[l] && l<s1.size()){
			l++;
		}
		while(s1[r]!=s2[r]&&r<s1.size()){
			r++;
		}
		ans=0;
		for(ll cl=l;cl>=0;cl--){
			for(ll cr=r+1;cr<=s1.size();cr++){
				if(m[s1.substr(cl,cr)]==s2.substr(cl,cr)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
