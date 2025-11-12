#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
pair<string,string> c[200001];
int q,n;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		cin.ignore();
		c[i].first=s1;
		c[i].second=s2;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		long long ans=0;
		cin>>s1>>s2;
		cin.ignore();
		for(int j=1;j<=n;j++){
			string s3=c[j].first;
			for(int k=0;k<s1.length();k++){
				int o=0;
				while(s1[k+o]==s2[o]&&o<s2.length()) o++;
				if(o==s2.length()-1) {
					string s4=s1,s5=c[j].first;
					for(int u=0;u<o;u++){
						s4[u+k]=s5[u];
					}
					if(s4==s2) ans++;
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}