#include<bits/stdc++.h>
using namespace std;
int n[10001],s[10001],x,y,z;
int main(){
	freopen("replace.in","t","file");
	freopen("replace.out","w","file");
	for(int i=0;i<=n[10001];i++){
		cin>>n[i]>>s[i]>>z>>x>>y;
		s[i]=abs(s[i]);
		s=x+y+z;
	cout<<s[i]<<" "<<x<<y<<z<<endl;	
	}
	
	return 0;
}
