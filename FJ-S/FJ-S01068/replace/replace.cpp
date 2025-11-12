#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[210000][2],s2[210000][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i)cin>>s1[i][0]>>s1[i][1];
	for(int i=1;i<=q;++i){
		cin>>s2[i][0]>>s2[i][1];
		for(int j=1;j<=n;++j){
			if(s2[i][0].find(s1[j][0])!=string::npos){
				string s3=s2[i][0];
				s3.replace(s2[i][0].find(s1[j][0]),s1[j][1].size(),s1[j][1]);
				if(s3==s2[i][1])++cnt;
			}
		}
		printf("%d\n",cnt);
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
