#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string>ma;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ma[s1]=s2;
	}
	while(m--){
		string t1,t2;
		cin>>t1>>t2;
		int cnt=0;
		for(auto s:ma){
			for(int i=0;i+s.first.size()-1<t1.size();++i){
				bool flag=true;
				for(int j=i;j<s.first.size()+i;j++){
					if(s.first[j-i]!=t1[j]) {
						flag=false;
					}
				}
				if(flag){
		 			//cout<<s.first<<' '<<s.second<<"->";
					string tt="";
					for(int k=0;k<t1.size();k++){
						if(k>=i&&k<=i+s.first.size()-1){
							tt+=s.second[k-i];
						} else{
							tt+=t1[k];
						}
					}
				//	cout<<tt<<endl; 
					if(tt==t2){
						//
						
						//cout<<tt<<endl;
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
