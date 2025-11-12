#include<bits/stdc++.h>
using namespace std;//s.find(o,begin);s.substr(begin,length);
string a[200005],b[200005],c,d;
int n,q,e=0,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}for(int i=0;i<q;i++){
		ans=0;
		cin>>c>>d;
		e=0;
		if(c.length()!=d.length()){
			cout<<0<<"\n";
			continue;
		}
		for(int j=0;j<n;j++){
			e=0;
			int q=c.find(a[j],e);
			//cout<<q;
			while(0<=q&&q<c.length()){
				if(d==c.substr(0,q)+b[j]+c.substr(q+b[j].length(),c.length()-q-b[j].length()) ){
					ans++;	
				}e=q+1;
				q=c.find(a[j],e);
			}
		}cout<<ans<<"\n";
	}
	/*
	string s="abcdefg";this is a case :))))
	cout<<s.find("defg",3);*/
	/*
	string s="abcdefg"; //s.substr(begin,length) :)
	cout<<s.substr(1,0);*/
	return 0;
}
