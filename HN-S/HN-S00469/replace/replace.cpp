#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[600000];
unsigned long long d[20000][2],f[200000];
bool ok=true;
struct code{
	unsigned long long a,b;
}sum[200000];
bool cmp(const code &a,const code &b){
	return a.a<b.a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		for(int j=1;j<=l;j++){
			sum[i].a=sum[i].a*27+(s[j]-'a'+1);
		}
		scanf("%s",s+1);
		l=strlen(s+1);
		for(int j=1;j<=l;j++)
			sum[i].b=sum[i].b*27+(s[j]-'a'+1);
	}
	sort(sum+1,sum+n+1,cmp);
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]*27;
	while(q--){
		char s1[600000],s2[600000];
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1),ll=strlen(s2+1);
		if(len!=ll){
			printf("0\n");
			continue;
		}
		int ans=0;
		int l=1,r=len;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		if((long long)(l*r)>=100000000){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=len;i++){
			d[i][0]=d[i-1][0]*27+(s1[i]-'a'+1);		
			d[i][1]=d[i-1][1]*27+(s2[i]-'a'+1);
		}
		for(int i=1;i<=len;i++)
			for(int j=1;j+i-1<=len;j++)
				if(j<=l&&i+j-1>=r){
					unsigned long long s=d[j+i-1][0]-d[j-1][0]*f[i],ss=d[i+j-1][1]-d[j-1][1]*f[i];
					for(int k=1;k<=n;k++)
						if(sum[k].a==s&&sum[k].b==ss) ans++;
				}
		printf("%d\n",ans);
	}
	return 0;
}
