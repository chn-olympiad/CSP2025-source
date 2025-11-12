#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}for(int j = 1;j<=q;j++){
		string sy,sr,s1,s2;
		cin>>sy>>sr;
		if(sy.size() == 1){
			bool p = 0;
			for(int i = 1;i<=n;i++){
				if(s[i][1] == sy&&s[i][2] == sr){
					cout<<sy.size()<<endl;
					p = 1;
					
				}
			}if(p == 0)cout<<0<<endl;
		}else{
			
			
			int ks = -1,js = -1;
			for(int i = 0;i<sy.size()-1;i++){
				if(sy[i]!=sr[i]&&ks == -1){
					ks = i;
				}if(sy[i]!=sr[i]&&ks!=-1&&sy[i+1]==sr[i+1]){
					js = i;
				}
			}
				
			
			if(js == -1){
				js = sy.size();
			}s1=sy.substr(ks,js-ks+1);
			s2=sr.substr(ks,js-ks+1);
			bool p = 0;
			for(int i = 1;i<=n;i++){
				if(s[i][1] == s1&&s[i][2] == s2){
					cout<<s1.size()<<endl;
					p = 1;
					
				}
			}if(p == 0)cout<<0<<endl;
		}
	}
	

return 0;

}
