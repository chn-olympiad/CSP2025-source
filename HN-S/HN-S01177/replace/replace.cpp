#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][2],t[100005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<=int(t[i][1].size())-int(s[j][1].size());k++){
			    
				string s1=t[i][1];
				if(s1.substr(k,s[j][1].size())==s[j][1]){
					for(int o=k;o<=k+s[j][1].size()-1;o++){
					    s1[o]=s[j][2][o-k];
				    }
				    if(s1==t[i][2]){
					    ans++;
				    }
				}
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
} 
