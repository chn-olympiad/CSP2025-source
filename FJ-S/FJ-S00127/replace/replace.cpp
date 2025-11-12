#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
string x,y,s,t;
int maxn1=INT_MIN,maxn2=INT_MIN,maxn3=INT_MIN;
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
	}
	for(int i=1;i<=m;i++){
		cin>>s>>t;
		sum=0;
		for(int k=0;k<=sizeof(s)-1;k++){
			if(s[k]!=t[k]){
				sum++;
		} 
		}
			cout<<sum;
	} 
	
	
	return 0;
} 
