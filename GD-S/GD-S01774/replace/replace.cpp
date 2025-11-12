#include<bits/stdc++.h>
#define N 200010
using namespace std;
int q,n,ans;
string s[N][2],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int m1=s1.size(),m2=s[i][0].size();
			for(int j=0;j<=m1-m2;j++){
				if(s[i][0][0]==s1[j]){
					register int k;
					for(k=1;k<m2;k++)
						if(s[i][0][k]!=s1[j+k]) break;
					if(k==m2){
						string s3=s1;
						for(k=0;k<m2;k++) s3[j+k]=s[i][1][k];
						if(s3==s2) ans++;
					}
				}
				
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
