#include<bits/stdc++.h>
using namespace std;
int n,q;
struct Node{
	string s1,s2;
}s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("relpace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		string s1,s2,x="";
		cin>>s1>>s2;
		int cnt=0;
		for(int i=0;i<s1.size();i++){
			for(int j=s1.size()-1;j>=i;j--){
				x="";
				string t1=s1,t2=s2;
				for(int k=i;k<=j;k++){
					x+=t1[k];
				}
				
				//cout<<x<<endl;
				
				bool f=0;
				for(int k=1;k<=n;k++){
					if(x==s[k].s1){
						x="";
						x=s[k].s2;
						f=1;
						break;
					}
				}
				if(f){
					for(int k=0;k<x.size();k++){
						t1[i+k]=x[k];
						//cout<<t1<<endl;
					}
					if(t1==t2)cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
