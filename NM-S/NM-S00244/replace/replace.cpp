#include<bits/stdc++.h>
using namespace std;
int main(){
	//string sb;
	//cin>>sb;
	//cout<<sb.substr(1,2);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[200005];
	map<string,string>owo;
	for(int i=1;i<=n;i++){
		string s2;
		cin>>s1[i]>>s2;
		owo[s1[i]]=s2;
	}for(int h=1;h<=q;h++){
		int ans=0;
		string sq1,sq2;
		cin>>sq1>>sq2;
		if(sq1.length()==sq2.length()){
			for(int i=1;i<=n;i++){
				//for(int j=0;j<sq1.length();j++){
					string qwq=sq1.substr(0,sq1.find(s1[i]))+owo[s1[i]]+sq1.substr(sq1.find(s1[i])+owo[s1[i]].length(),sq1.length()-1);
					if(qwq==sq2){
						ans++;
					}
				//}
			}
			
		}cout<<ans<<"\n";
	}
	return 0;
	
}
