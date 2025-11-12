#include<bits/stdc++.h>
using namespace std;
int n,q;
char a[5000006],b[5000006];
string s[200005][2];
int main(){
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> s[i][0] >> s[i][1];
	if(n>1000){
		int p[200005],x,y;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][0].size();j++)if(s[i][0][j]=='b'){
				x=j;
				break;
			}
			for(int j=0;j<s[i][1].size();j++)if(s[i][1][j]=='b'){
				y=j;
				break;
			}
			p[x-y]++;
		}
		while(q--){
			cin >> a >> b;
			for(int j=0;a[j];j++)if(a[j]=='b'){
				x=j;
				break;
			}
			for(int j=0;b[j];j++)if(b[j]=='b'){
				y=j;
				break;
			}
			printf("%d\n",p[x-y]);
		}
	}
	while(q--){
		int ans=0;
		cin >> a >> b;
		for(int i=1;i<=n;i++){
			for(int j=0;a[j];j++){
				bool flag=1;
				for(int k=0;k<s[i][0].size();k++){
					if(a[j+k]!=s[i][0][k]||!a[j+k]){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
					for(int k=0;k<s[i][1].size();k++)swap(a[j+k],s[i][1][k]);
					for(int k=0;a[k];k++)if(a[k]!=b[k]){
						ans--;
						break;
					}
					for(int k=0;k<s[i][1].size();k++)swap(a[j+k],s[i][1][k]);
				}
			}
		}
		printf("%d\n",ans);
	}
}