//GZ-S00265 毕节梁才学校 杨文涯杰
#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200000+10];
string p[200000+10];
int len[200000+10];
int idx1[200000+10];
int idx2[200000+10];
int cnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>p[i];
		len[i]=s[i].size();
		for(int j=0;j<len[i];j++){
			if(s[i][j]=='b') idx1[i]=j;
			if(p[i][j]=='b') idx2[i]=j;
		}
	}
	while(q--){
		cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		int nee1,nee2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b') nee1=i;
			if(s2[i]=='b') nee2=i;
		}
		for(int i=1;i<=n;i++){
			if((nee2-nee1==idx2[i]-idx1[i])&&nee1>=idx1[i]&&s1.size()-nee2>=len[i]-idx2[i]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
} 
