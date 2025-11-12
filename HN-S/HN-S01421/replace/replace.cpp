#include<bits/stdc++.h>
using namespace std;
int sc[100000];
int tc[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n];
	string s2[n];
	
	string t1[n];
	string t2[n];
	
	for(int i=0;i<n;i++){
		cin>>t1[i]>>t2[i];
		int t1w=0,t2w=0;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]=='b') t1w=j;
			if(t2[i][j]=='b') t2w=j;
		}
		tc[i]=t1w-t2w;

	}
	for(int i=0;i<q;i++){
		cin>>s1[i]>>s2[i];
		int s1w=0,s2w=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b') s1w=j;
			if(s2[i][j]=='b') s2w=j;
		}
		
		sc[i]=s1w-s2w;

	}
	
	for(int i=0;i<q;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(sc[i]==tc[j]){
				sum++;
				
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
	
} 
