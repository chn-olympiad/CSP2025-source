#include<bits/stdc++.h>
using namespace std;
int n,q,sz[200005];
string s1[200005],s2[200005];
vector<int> v1[200005],v2[200005];
char t1[5000005],t2[5000005];
int sm,f1[5000005],f2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sz[i]=s1[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		v1[i].resize(s1[i].size());
		int k=0;
		v1[i][1]=0;
		for(int j=2;j<s1[i].size();j++){
			while(k&&s1[i][j]!=s1[i][k+1]) k=v1[i][k];
			if(s1[i][j]==s1[i][k+1]) k++;
			v1[i][j]=k;
//			printf("%d ",k);
		}
//		printf("\n");
		v2[i].resize(s2[i].size());
		k=0;
		v2[i][1]=0;
		for(int j=2;j<s2[i].size();j++){
			while(k&&s2[i][j]!=s2[i][k+1]) k=v2[i][k];
			if(s2[i][j]==s2[i][k+1]) k++;
			v2[i][j]=k;
//			printf("%d ",k);
		}
		sm+=(int)(s1[i]==s2[i]);
//		printf("\n");
	}
	while(q--){
		cin>>(t1+1)>>(t2+1);
		int n1=strlen(t1+1),n2=strlen(t2+1),l=-1,r;
		if(n1!=n2){
			cout<<0<<'\n';
		}else{
			for(int i=1;i<=n1;i++){
				if(t1[i]!=t2[i]){
					r=i;
					if(l==-1) l=i;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(sz[i]>=(r-l+1)){
					int k=0;
					for(int j=r-sz[i]+1;j<=l+sz[i]-1;j++){
						while(k&&(k==sz[i]||s1[i][k+1]!=t1[j])) k=v1[i][k];
						if(s1[i][k+1]==t1[j]) k++;
						f1[j]=k;
					}
					k=0;
					for(int j=r-sz[i]+1;j<=l+sz[i]-1;j++){
						while(k&&(k==sz[i]||s2[i][k+1]!=t2[j])) k=v2[i][k];
						if(s2[i][k+1]==t2[j]) k++;
						f2[j]=k;
					}
					for(int j=r;j<=l+sz[i]-1;j++){
						if(f1[j]==sz[i]&&f2[j]==sz[i]) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
