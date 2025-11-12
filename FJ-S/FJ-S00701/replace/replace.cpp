#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=2e5+10;
int n,q,c[N];
bool cc[N];
string s[N][3];
string t1,t2;
bool flag;
map<string,int> l;
int f(string t){
	for(int i=0;i<t.length();i++){
		if(t[i]=='b'){
			return i;
		}
	} 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("relpace.out","w",stdout);
//	string qq;
//	cin>>qq;
//	cout<<f(qq)<<endl;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		string h=s[i][1]+s[i][2];
		if(l[h]==0) l[h]++;
		else i--,n--;
	} 
	for(int i=1;i<=n;i++){
		c[i]=f(s[i][1])-f(s[i][2]);
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		int x=f(t1)-f(t2);
		for(int i=1;i<=n;i++){
			if(s[i][1].length()>t1.length())continue;
			if(c[i]==x) ans++;
		}
		cout<<ans<<endl;
		continue;
	}	
}
