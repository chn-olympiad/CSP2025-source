#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=
	0,anb=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==0) anb++;
	}
	for(int i=1;i<=n;i++){
		ans*=i;	
	}
	cout<<ans-anb;
} 
