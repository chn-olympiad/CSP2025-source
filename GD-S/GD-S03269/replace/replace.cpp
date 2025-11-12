#include<bits/stdc++.h>
using namespace std;
map<string,string>s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[s1]=s2;
	} 
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		string x;
		for(int j=-1;j<t1.size();j++){
			string y="",z;
			if(j==-1)x="";
			else x+=t1[j];
			int k=j+1;
			while(k<t1.size()){
				if(s[y]!=""){
					int v=k+1;
					while(v<t1.size()){
						z+=t1[v];
						v++;
					}
					if(x+s[y]+z==t2)ans++;
				} 
				y+=t1[k];
				k++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
