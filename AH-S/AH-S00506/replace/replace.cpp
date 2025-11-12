#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
		while(q--){
		cin>>s1>>s2;
		int len=s1.size(),len2=s2.size();
		if(len!=len2){
			cout<<0<<endl;
		}else{
			int way=0;
			for(int i=0;i<len;i++){
				for(int j=i;j<len;j++){
					string tmp=s1.substr(i,j-i+1);
					if(mp.count(tmp)){
						tmp=mp[tmp];
						string x="",z="";
						if(i!=0)x=s1.substr(0,i);
						if(j!=len-1)z=s1.substr(j+1,len-j-1);
						if(x+tmp+z==s2){
							 way++;
							 
						}
					}
				}
			}
			cout<<way<<endl;
		}
	}
	return 0;
}
