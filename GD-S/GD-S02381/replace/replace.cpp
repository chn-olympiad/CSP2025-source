# include<cmath>
# include<cstdio>
# include<cstring>
# include<iostream>
# include<algorithm>
# define I inline int
# define V inline void
# define ll long long
const int N=5e6+10;
using namespace std;
int n,q,ans;
int a[N],b[N];
char s[105][3][N],t[3][N];
bool pd1(int x) {
	for(int i=1;i<=x;i++) 
		if(t[1][i]!=t[2][i]) return 0;
	return 1;
}
bool pd2(int x) {
	for(int i=x;i<=strlen(t[1]);i++) {
		if(t[1][i]!=t[2][i]) return 0;
	}
	return 1;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%s%s",s[i][1]+1,s[i][2]+1);
	} 
	while(q--) {
		ans=0;
		scanf("%s%s",t[1]+1,t[2]+1);
		if(strlen(t[1])!=strlen(t[2])) {
			printf("0\n");
			continue;
		}
		int len=strlen(t[1]);
		for(int i=1;i<=n;i++) {
			int lens=strlen(s[i][2]);
			int tot1=0,tot2=0;
			for(int j=1;j<=len-lens+1;j++) {
				int fl=0;
				for(int k=1;k<=lens;k++) {
					if(t[2][j+k]!=s[i][2][k]) {
						fl=1;
						break;
					}
				} 
				if(!fl) {
					a[++tot1]=i;
				}
			}
			for(int j=1;j<=len-lens+1;j++) {
				int fl=0;
				for(int k=1;k<=lens;k++) {
					if(t[1][j+k]!=s[i][1][k]) {
						fl=1;
						break;
					}
				} 
				if(!fl) {
					b[++tot2]=i;
				}
			}
			for(int i=1,j=1;i<=tot1;) {
				if(a[i]==b[j]) {
					if(pd1(a[i]-1) && pd2(a[i]+lens)) ans++; 
					i++,j++;
				} else {
					if(a[i]>b[j]) j++;
					else i++;
				}
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
} 
