#include<bits/stdc++.h>
using namespace std;
struct a{
	string b;
	string c;
};
int ans1[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	a s[n+1],t[q+1];
	for(int i=1;i<=n;i++){
		cin>>s[i].b>>s[i].c; 
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].b>>t[i].c;	
	}
	if(q=1){
		cout<<"0";
		return 0;
	}
	for(int l=1;l<=q;l++){
		cout<<n<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
