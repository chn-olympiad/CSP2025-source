#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n],s1[n];
	for(int i=0;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<=n;j++){
			cin>>s1[j];
	}
}
	string t[q],t1[q]
	for(int i=0;i<=q;i++){
		cin>>t[i];
		for(int j=0;j<=q;j++){
			cin>>t1[j];
	}
}
	for(int i=0;i<=n;i++){
		if(s[i].size()=s1[i].size()){
			s[i]+=s1[i];
		}
	}
	for(int i=0;i<=q;i++){
		if(s[i].size()=t[i].size()){
			s[i]+=t[i];
			if(s[i].size()=t1[i].size()){
				s[i]+=t1[i];
			}
		}
	}
	for(int i=0;i<=q;i++){
		cout<<s[i];
	}
	return 0;
}
