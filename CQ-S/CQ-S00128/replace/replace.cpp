#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
string s1[N],s2[N];
char t1[M],t2[M],a[M],b[M];
int len[N],ans,nxt[M],f[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a+1>>b+1;
		len[i]=strlen(a+1);
		for(int j=1;j<=len[i];j++){
			s1[i][j]=a[j],s2[i][j]=b[j];
		}
	}
	while(q--){
		cin>>t1+1>>t2+1;
		int m=strlen(t1+1);
		for(int w=1;w<=n;w++){
			nxt[1]=0;
			for(int i=2,j=0;i<=len[w];i++){
				while(j&&s1[w][i]!=s1[w][j+1]) j=nxt[j];
				if(s1[w][i]==s1[w][j+1]) j++;
				nxt[i]=j;
			}
			for(int i=1,j=0;i<=m;i++){
				while(j&&(j==len[w]||t1[i]!=s1[w][j+1])){
					j=nxt[j];
				}
				if(t1[i]==s1[w][j+1]) j++;
				f[i]=j;
				if(f[i]==len[w]){
					bool flag=1;
					for(int k=1;k<=i-len[w];k++){
						if(t1[k]!=t2[k]){
							flag=0;
							break;
						}
					}
					for(int k=i-len[w]+1;k<=i;k++){
						if(s2[w][k-i+len[w]]!=t2[k]){
							flag=0;
							break;
						}
					}
					for(int k=i+1;k<=m;k++){
						if(t1[k]!=t2[k]){
							flag=0;
							break;
						}
					}
					if(flag) ans++;
				}
			}
			memset(nxt,0,sizeof(nxt));	
			memset(f,0,sizeof(f));
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}

