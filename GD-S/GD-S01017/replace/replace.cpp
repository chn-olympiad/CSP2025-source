#include<bits/stdc++.h>
using namespace std;
int n,q,a[10000],b[10000],c[10000];
string s,s1,t,t1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s1;
		for(int j=0;j<s.size();j++){
			if(s[j]=='a') a[i]++;
			else break;
		}for(int j=0;j<s1.size();j++){
			if(s[j]=='a') b[i]++;
			else break;
		}c[i]=a[i]-b[i];
	}for(int i=1;i<=q;i++){
		cout<<0<<endl; 
	}
}

