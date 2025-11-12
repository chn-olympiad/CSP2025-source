#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int MN=1e3+5,ML=2000+5;
int n,q;
int pi[MN][ML];
string s1[MN],s2[MN];
void build(string s,int k){
	pi[k][0]=0;
	for(int i=1;i<s.length();++i){
		int j=pi[k][i-1];
		while(j>0&&s[i]!=s[j]){
			j=pi[k][j];
		}
		if(s[i]==s[j])++j;
		pi[k][i]=j;
	}
}
int ans=0;
void find(const string &s,const string &q){
	int j=0;
	for(int k=1;k<=n;++k){
		for(int i=0;i<=s.length();++i){
			if(s1[k][j]==s[i])++j;
			else j=pi[k][j]+1;
			if(j==s1[k].length()){
				string s3="";
				for(int r=0;r<i-j+1;++r){
					s3=s3+s[r];
					//cout<<s[r]<<" ";
				}
				s3=s3+s2[k];
				for(int r=i+1;r<s.length();++r){
					s3=s3+s[r];
					//cout<<s[r]<<" ";
				}
				//cout<<s<<" "<<s.substr(0,i-j+1)<<" "<<s.substr(i+1)<<" "<<s3<<" "<<s2[k]<<" "<<s1[k]<<" "<<endl;
				if(s3==q)++ans;
				j=0;
			}
		}
	}
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		build(s1[i],i);
	}
	string q1,q2;
	for(int i=1;i<=q;++i){
		cin>>q1>>q2;
		ans=0;
		find(q1,q2);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
