#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> mp;
int n,q;
long long ans;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		string k1,k2;
		int st=0,en=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				if(st!=0)st=j;
				k1+=t1[j];
				k2+=t2[j];
			}
			if(t1[j-1]!=t2[j-1]&&j!=0)en=j;
		}
		string h1=k1,h2=k2;
		if(mp[k1]==k2)ans++;
		for(int j=0;j<=st;j++){
			for(int p=0;p<=t1.size()-en;p++){
				h1=k1,h2=k2;
				for(int x=st-1;st-x+1<=j;x++){
					h1=t1[x]+h1;
					h2=t2[x]+h2;
				}
				for(int y=en;y-en+1<=p;y++){
					h1=h1+t1[y];
					h2=h2+t2[y];
				}
				if(mp[h1]==h2)ans++;
			}
		}	
		cout<<ans<<endl;
	}
	return 0;
}
