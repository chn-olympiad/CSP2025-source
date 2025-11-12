#include<bits/stdc++.h>
using namespace std;
int n,q,x,ans;
struct a{
	string a,b;
}s[200010],t[200010];
string stuber(string s1,string s2,string s3){
	x=s1.find(s2);
	if(x!=-1){
		for(int i=0;i<s3.size();i++){
			s1[x+i]=s3[i];
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0;i<q;i++){
		cin>>t[i].a>>t[i].b;
	}
	for(int i=0;i<q;i++){
		ans=0;
		for(int j=0;j<n;j++){
			stuber(t[i].a,s[j].a,s[j].b);
			if(t[i].a==t[i].b){
				ans++;
				stuber(t[i].a,s[j].b,s[j].a);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
