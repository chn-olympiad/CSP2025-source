#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct re{
	string s1,s2;
};
bool findd(string s,string b){
	int f=0;
	for(int i=0;i<b.length();i++){
		if(b[i]==s[0]){
			f=1;
			for(int j=i;j<s.length();j++){
				if(s[j]!=b[j]){
					f=0;
				}
			} 
		} 
	} return f;
}
 re s[200005],t[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
		
	} 
	for(int i=0;i<q;i++){
		int sum=0;
		cin>>t[i].s1>>t[i].s2;
		for(int j=0;j<n;j++){
			if(findd(s[j].s1,t[i].s1)&&findd(s[j].s2,t[i].s2)){
				sum++;
			}
		}cout<<sum<<endl;
	}
	return 0;
}
