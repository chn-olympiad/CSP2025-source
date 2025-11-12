#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
const int maxm=2e5+10;
int n,q;
char s[10000][2][3000];
char t1[maxn];
char t2[maxn];
int ans=0;
int len;
void print(int l,int r,int k,bool flag,int ans,char c1[],char s1[]){
	printf("l:%d r:%d k:%d f:%d ans:%d %s %s\n",l,r,k,flag,ans,c1,s1);
}
void dfs(char c[]){
	ans=0;
	for(int l=0;l<len;l++){
		for(int r=l;r<len;r++){//循环区间 
			for(int k=1;k<=n;k++){//每个 二元组 
				int len2=strlen(s[k][0]);
				if((r-l+1)!=len2){
					continue;
				}
				bool flag=0;
				for(int i=l,j=0;i<=r && j<strlen(s[k][0]);i++,j++){
					if(c[i]!=s[k][0][j]){
						flag=1;
						break;
					}
				}
//				print(l,r,k,flag,ans,c,s[k][0]);
				if(!flag){
					for(int i=l,j=0;i<=r && j<strlen(s[k][0]);i++,j++){
						c[i]=s[k][1][j];
					}
//					cout<<c<<" "<<t2<<endl;
					bool flag2=0;
					for(int i=0;i<len;i++){
						if(c[i]!=t2[i]){
							flag2=1;
							break;
						}
					}
					if(!flag2){
						ans++;
					}
					for(int i=l,j=0;i<=r && j<strlen(s[k][0]);i++,j++){
						c[i]=s[k][0][j];
					}
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		len=strlen(t1);
		dfs(t1);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
