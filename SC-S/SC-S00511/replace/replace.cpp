#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=2005;
int n,m,sz[N];
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][0].size();
//		printf("-- %d %d\n",wal[i],war[i]);
	}
	for(int i=1;i<=m;i++){
		cin>>t[0]>>t[1];
		int len=t[0].size(),sum=0,warl,warr;
		if((int)t[1].size()!=len){
			printf("0\n");
			continue;
		}
		for(int j=0;j<len;j++){
			if(t[0][j]!=t[1][j]){
				warl=j;
				break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(t[0][j]!=t[1][j]){
				warr=j;
				break;
			}
		}
//		printf("- %d %d\n",warl,warr);
		for(int j=1;j<=n;j++){
			if(sz[j]<warr-warl+1)
				continue;
			for(int k=max(0,warr-sz[j]+1);k+sz[j]-1<len&&k<=warl;k++){
//				printf("--- j=%d,k=%d\n",j,k);
				bool cmp=1;
				for(int l=0;l<sz[j];l++)
					if(t[0][l+k]!=s[j][0][l]||t[1][l+k]!=s[j][1][l]){
//						printf("--------- %d %c %c\n",l,t[0][l+k],s[j][0][l+k]);
						cmp=false;
						break;
					}
				if(cmp)
					sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}