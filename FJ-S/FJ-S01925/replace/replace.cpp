#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
char s1[10010][10010];
char s2[10010][10010];
char k1[10010];
char k2[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>k1>>k2;
		for(int j=1;j<=n;j++){
			int l1=strlen(s1[j]);
			int l2=strlen(k1);
			int f=0;
			for(int z=0;z<l2;z++){
				if(k1[z]==s1[i][f]&&k2[z]==s2[i][f]){
					f++;
				}else if(k1[z]==k2[z]&&f!=l1-1&&(k1[z]!=s1[i][f]||k2[z]!=s2[i][f])){
					f=0;
				}else if(k1[z]!=k2[z]&&(k1[z]!=s1[i][f]||k2[z]!=s2[i][f])){
					break;
				}
				if(f==l1-1&&z==l2-1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
