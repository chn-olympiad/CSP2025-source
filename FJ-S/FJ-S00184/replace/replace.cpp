#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[2500001],s2[2500001],b[200001],bb[200001],b1[200001],bb1[200001],c[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",&s1);
		scanf("%s",&s2);
		int l=strlen(s1);
		for(int j=0;j<l;j++)if(s1[j]=='b')b[i]=j,bb[i]=l-j;
		for(int j=0;j<l;j++)if(s2[j]=='b')b1[i]=j,bb1[i]=l-j,c[i]=b[i]-j;
	}
	while(q--){
		long long s=0;
		scanf("%s",&s1);
		scanf("%s",&s2);
		int l=strlen(s1),bk,ck,bbk,bk1,bbk1;
		for(int j=0;j<l;j++)if(s1[j]=='b')bk=j,bbk=l-j;
		for(int j=0;j<l;j++)if(s2[j]=='b')bk1=j,bbk1=l-j,ck=bk-j;
		for(int i=1;i<=n;i++)if(bk>=b[i]&&bbk>=bb[i]&&bk1>=b1[i]&&bbk1>=bb1[i]&&ck==c[i])s++;
		printf("%d\n",s);
	}
	return 0;
}
