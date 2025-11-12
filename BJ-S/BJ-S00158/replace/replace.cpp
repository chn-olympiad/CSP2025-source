#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int as[a][4];
	for(int i=0;i<a;++i){
		string str1,str2;
		cin>>str1>>str2;
		for(int j=0;j<str1.size();++j){
			if(str1[j]=='b'){as[i][0]=j;as[i][1]=str1.size()-j-1;break;}
		}
		for(int j=0;j<str2.size();++j){
			if(str2[j]=='b'){as[i][2]=j;as[i][3]=str1.size()-j-1;break;}
		}
	}
	while(b--){
	string s1,s2;
	int ans=0;
	int as1,as2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size())cout<<0<<endl;
	else{
	for(int j=0;j<s2.size();++j){
			if(s1[j]=='b'){as1=j;break;}
		}
		for(int j=0;j<s2.size();++j){
			if(s2[j]=='b'){as2=j;break;}
		}
		for(int i=0;i<a;++i){
			if(as[i][0]-as[i][2]==as1-as2)ans++;
		}
		cout<<ans<<endl;;
	}
	}
}
