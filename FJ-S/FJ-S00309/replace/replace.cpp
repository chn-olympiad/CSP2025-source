#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int n,q,ans;
vector<pair<string,string> >v[30];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		//v[s1[0]-'a'+1].push_back(make_pair(s1,s2));
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		ans=0;
		for(int j=0;j<s1.size();j++){
			for(int k=0;k<v[s1[j]-'0'+1].size();k++){
				bool f=1;
				for(int p=0;p<v[s1[j]-'0'+1][k].first.size();p++){
					if(s1[j+p]!=v[s1[j]-'0'+1][k].first[p]){
						f=0;
						break;
					}
				}
				if(f){
					string s3=s1;
					for(int p=0;p<v[s1[j]-'0'+1][k].first.size();p++){
						s3[j+p]=v[s1[j]-'0'+1][k].first[p];	
					}
					if(s3==s2)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}