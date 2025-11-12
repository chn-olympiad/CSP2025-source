#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2,s3="",s4="";
		cin>>s1>>s2;
		int flag=0,f=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				flag=1;
			}
			if(flag==1){
				s3+=s1[j];
				s4+=s2[j];
			}
			if(s1[j]==s2[j]){
				f=1;
			}
		}
		if(f==0){
			s[i][1]=s1;
			s[i][2]=s2;
			continue;
		}
		for(int j=s3.size()-1;j>=0;j--){
			if(s3[j]!=s4[j]){
				break;
			}
			if(s3[j]==s4[j]){
				s3[j]=' ';
				s4[j]=' ';
			}
		}
		string s5="",s6="";
		for(int j=0;j<=s3.size();j++){
			if(s3[j]=='0'||s3[j]==' '){
				break;
			}
			s5+=s3[j];
			s6+=s4[j];
		}
		s[i][1]=s5;
		s[i][2]=s6;
	}
	
	while(q--){
		string s1,s2,s3="",s4="";
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int flag=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				flag=1;
			}
			if(flag==1){
				s3+=s1[j];
				s4+=s2[j];
			}
		}
		for(int j=s3.size()-1;j>=0;j--){
			if(s3[j]!=s4[j]){
				break;
			}
			if(s3[j]==s4[j]){
				s3[j]=' ';
				s4[j]=' ';
			}
		}
		string s5="",s6="";
		for(int j=0;j<=s3.size();j++){
			if(s3[j]=='0'||s3[j]==' '){
				break;
			}
			s5+=s3[j];
			s6+=s4[j];
		}
		int ans=0;
		string x="",y="",z="";
		for(int i=1;i<=n;i++){
			if(s5==s[i][1]&&s6==s[i][2]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
