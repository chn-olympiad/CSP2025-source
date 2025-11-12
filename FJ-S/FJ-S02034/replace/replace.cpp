#include<bits/stdc++.h>
using namespace std;
int n,p;
string a[200005],b[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(p--){
		cin>>t1>>t2;
		int l=t1.length(),cnt=0;;
		string s1="",s2="";
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){s1+=t1[i]; s2+=t2[i];
			} 
			if(t1[i]==t2[i]&&t1[i+1]!=t2[i+1]){
				cout<<0;
				return 0;
			}
		} 
		for(int i=1;i<=n;i++){
			if(a[i]==s1 && b[i]==s2) cnt++;
		
		}
		cout<<cnt<<"\n"; 
	}
	return 0;
}
