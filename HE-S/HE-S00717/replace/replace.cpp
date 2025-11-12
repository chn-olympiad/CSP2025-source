#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
int n,q;
string s[maxn][3];
int find_(string a,int pos,string b){
	for(int i=pos;i<a.size();i++){
		bool f=1;
		for(int j=0;j<b.size();j++){
			if(a[i+j]!=b[j]){
				f=0;
			}
		}
		if(f==1) return i;
	}
	return a.size();
}
string tihuan(string a,int pos,string b){
	string s1,s2;
	for(int i=0;i<pos;i++){
		s1=s1+a[i];
	}
	for(int i=pos+b.size();i<a.size();i++){
		s2=s2+a[i];
	}
	return s1+b+s2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int it=find_(t1,0,s[i][1]);
			while(it!=t1.size()){
				if(tihuan(t1,it,s[i][2])==t2){
					ans++;
				}
				it=find_(t1,it+1,s[i][1]);
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
