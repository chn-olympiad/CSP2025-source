#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1e6+8;
int n,q;
string s[N][2];
int sz[N];
string t[2];
int ans,len;
void work(){
	for(int i=1;i<=len;i++){
		for(int j=1;j<=n;j++){
			bool flag=1;
			for(int k=1;k<=sz[j];k++){
				if(t[0][i+k-1]==s[j][0][k]) continue;
				flag=0;
				break;
			}
//			printf("%d %d %d\n",i,i+sz[j]-1,j);	
			if(flag){
				string str=t[0]; 
				for(int k=1;k<=sz[j];k++){
					str[i+k-1]=s[j][1][k];
				}
				if(str==t[1]) ans++;
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][0].size();
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		len=t[0].size();
		ans=0;
		t[0]=" "+t[0];
		t[1]=" "+t[1];
		work();
		printf("%d\n",ans);
	}
	return 0;
}
