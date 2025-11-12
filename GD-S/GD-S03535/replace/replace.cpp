#include<bits/stdc++.h>
#include<cstdio>
#include<locale.h>
using namespace std;
int n,q,ans,c[2*100000+5];
string s[2*100000+5][3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		int qp,pq;
		cin>>s[i][1]>>s[i][2];
		for(int j=0;j<s[i][1].size()-1;j++){
			if(s[i][1][j]=='b') qp=j;
		}
		for(int j=0;j<s[i][2].size()-1;j++){
			if(s[i][2][j]=='b') pq=j;
		}
		c[i]=qp-pq;
	}
	while(q--){
		int qp,pq;
		ans=0;
		cin>>t[1]>>t[2];
		for(int i=1;i<=n;i++){
			if(t[1][i]=='b') qp=i;
		}
		for(int i=1;i<=n;i++){
			if(t[2][i]=='b') pq=i;
		}
		int cc=qp-pq;
		for(int i=1;i<=n;i++){
			if(cc==c[i]) ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
