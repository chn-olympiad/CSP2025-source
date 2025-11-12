#include<bits/stdc++.h> 
using namespace std;
int n,q,ls[200005],lt[200005],l[200005],r[200005],ans[200005],fail[200005];
char S[5000005];
vector<int> s[200005],t[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",S+1);
		ls[i]=strlen(S+1);
		s[i].resize(ls[i]+1);
		for(int j=1;j<=ls[i];j++)s[i][j]=s[i][j]*27+S[j]-'a';
		scanf("%s",S+1);
		for(int j=1;j<=ls[i];j++)s[i][j]=s[i][j]*27+S[j]-'a';
	}
	for(int i=1;i<=q;i++){
		scanf("%s",S+1);
		lt[i]=strlen(S+1);
		t[i].resize(lt[i]+1);
		for(int j=1;j<=lt[i];j++)t[i][j]=t[i][j]*27+S[j]-'a';
		scanf("%s",S+1);
		for(int j=1;j<=lt[i];j++)t[i][j]=t[i][j]*27+S[j]-'a';
		l[i]=1;
		while(t[i][l[i]]/27==t[i][l[i]]%27)l[i]++;
		r[i]=lt[i];
		while(t[i][r[i]]/27==t[i][r[i]]%27)r[i]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=2,last=0;j<=ls[i];j++){
			while(last&&s[i][last+1]!=s[i][j])last=fail[last];
			if(s[i][last+1]==s[i][j])last++;
			fail[j]=last;
		}
		for(int j=1;j<=q;j++){
			for(int k=1,last=0;k<=lt[j];k++){
				while(last&&s[i][last+1]!=t[j][k])last=fail[last];
				if(s[i][last+1]==t[j][k])last++;
				if(last==ls[i]&&k>=r[j]&&k-ls[i]+1<=l[j])ans[j]++;
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
}
