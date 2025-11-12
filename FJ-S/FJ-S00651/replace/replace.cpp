#include<bits/stdc++.h>
using namespace std;
int ans=0,n,q;
string s1[500000],s2[5000000];
void solve(string x,string y){
	string z,a;
	int e=0;
	for(int i=0;i<n;i++){
		if(s1[i]==x&&s2[i]==y) ans+=1;
		if(x[i]!=y[i]){
		    z+=x[i];
		    a+=y[i];
		}
		else{
			if(z!=" "){
				cout<<z<<endl;
				e+=1;
				if(e>2) return;
				for(int j=0;j<n;j++){
					string b,c;
					if(z[j]==s1[i][j]||a[i]==s2[i][j]){
						for(int k=0;k<=i-z.length();k++) b+=x[i];
						for(int k=i;k<x.length()-1;k++) c+=x[i];
						x=b+z+c;
					}
				}
			} 
		}
	}
	if(x==y) ans+=1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		string s3,s4;
		cin>>s3>>s4;
		ans=0;
	//	solve(s3,s4);
		cout<<0;
	}
	return 0;
}
