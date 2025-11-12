#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1,s2;
int ks,js;
string a[200005],b[200005];
string tq(string&s,int st,int en){
	string ss="";
	for(;st<=en;st++){
		ss+=s[st];
//		cout<<ss;
	}
	return ss;
}
void check(int add,int i){
	if(tq(s2,add,add+a[i].size()-1)==b[i]){
		if(tq(s1,0,add-1)==tq(s2,0,add-1)&&tq(s1,add+a[i].size(),s1.size()-1)==tq(s2,add+a[i].size(),s2.size()-1)){
			ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(int)s1.size()-(int)a[i].size();){
				int k;
				for(k=0;k<a[i].size();k++){
					if(a[i][k]!=s1[j+k])break;
				}
				if(k==a[i].size())check(j,i);
				if(k!=0)j+=k;
				else j++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}