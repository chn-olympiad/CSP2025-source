#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
const long long mo=998244353;
string s;
long long s1=1,s2=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;  
	int l=n;                    
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)l--;
	}
	for(int i=m+1;i<=l;i++)s1=s1*i;
	for(int i=1;i<=l-m;i++)s2=s2*i;
	cout<<s1/s2;
	/*
     
	*/
}
