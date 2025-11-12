#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		string x,y,z;
		int ans=0;
		for(int i=0;i<t1.size()-1;i++){
			for(int j=i+1;j<=t1.size();j++){
				x=y=z="";
				for(int k=0;k<i;k++){
					x+=t1[k];
				}
				for(int k=i;k<j;k++){
					y+=t1[k];
				}
				for(int k=j;k<t1.size();k++){
					z+=t1[k];
				}
				if(y==""){
					continue;
				}
				for(int k=1;k<=n;k++){
					if(y==s1[k]){
						y=s2[k];
						break;
					}
				}
				if(x+y+z==t2){
					ans++;
					cout<<y<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
