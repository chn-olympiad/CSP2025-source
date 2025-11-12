#include<bits/stdc++.h>
using namespace std;
int n,q,l,ans;
string s[200010][3],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		l=t1.length(),ans=0;
		for(int i=0;i<l;i++){
			bool flag=true;
			for(int j=1;j<=n;j++){
				flag=true;
				for(int k=0;k<s[j][1].length();k++){
					if(t1[i+k]!=s[j][1][k]){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int k=0;k<s[j][2].length();k++){
						if(t2[i+k]!=s[j][2][k]){
							flag=false;
							break;
						}
					}
				}
				if(flag){
					for(int k=i+s[j][2].length();k<l;k++){
						if(t2[k]!=t1[k]){
							flag=false;
							break;
						}
					}
				}
				if(flag) ans++;
			}
			if(t1[i]!=t2[i] && !flag) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
