#include<bits/stdc++.h>
using namespace std;
string s[200005][5],t[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int m=1;m<=q;m++){
		int l=-1,r=-1,l1=-1,r1=-1;
		for(int i=0;i<t[m][1].size();i++){
			if(t[m][1][i]!=t[m][2][i]&&l==-1){
				l=i;
				r=i;
			}else if(t[m][1][i]!=t[m][2][i]){
				r=i;
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			l1=-1;
			r1=-1;
			for(int j=0;j<t[m][1].size();j++){
				flag=1;
				if(t[m][1][j]==s[i][1][0]&&t[m][2][j]==s[i][2][0]){
					l1=j;
					for(int k=1;k<s[i][1].size();k++){
						if(s[i][1][k]!=t[m][1][j+k]||s[i][2][k]!=t[m][2][j+k]){
							flag=0;
							break;
						}
						r1=j+k;
					}
					if(flag==0){
						l1=-1;
						r1=-1;
						continue;
					}
					if(l1<=l&&r1>=r){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}