#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
typedef long long ll;
const int mod=998244353;
string s1[10005],s2[10005];
string s3[10005],s4[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s3[i];
		cin>>s4[i];
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k+s2[j].size()<s3[i].size();k++){
				string tmp=s3[i].substr(0,k);
				string tmp1=s3[i].substr(k+1,k+s2[j].size());
				if(tmp1==s1[i]){
					tmp+=s2[j];
					tmp+=s3[i].substr(k+s2[j].size()+1);
					if(tmp==s4[i])ans++;
				}
			}
		}
	}
}
