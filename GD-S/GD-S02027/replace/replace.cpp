#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<string,string>m;
ll n,q,ans;
string s1,s2;
int main(){
	ll i,j;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
		m[s2]=s1;
	}
	while(q--){
		cin>>s1>>s2;
		ans=0;
		for(i=1;i<=s1.length();i++)
		for(j=0;j<s1.length()-i+1;j++){
			string s3="";
			s3=s1.substr(0,j);
			s3+=m[s1.substr(j,i)];
			s3+=s1.substr(j+i,s1.length()-j-i);
			if(s3==s2) ans++;
		}
		cout<<ans<<endl;
	}
}
