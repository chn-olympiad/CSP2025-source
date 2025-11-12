#include<bits/stdc++.h>
const int N=2*1e5+5,p=3499483;
int n,q,cnt,ca[N][2],cb[N][2];
long long hasha[N][2],hashb[2][N],po[N];
std::string s[N][2],t[N][2];
std::vector<int> a[N*2];
char ch;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	getchar();
	for(int i=1;i<=n;i++){
		ch=getchar();
		while(ch<='x'&&ch>='a')s[i][0]+=ch,ch=getchar();
		ch=getchar();
		while(ch<='x'&&ch>='a')s[i][1]+=ch,ch=getchar();
		cnt+=s[i][0].size()+s[i][1].size();
	}
	for(int i=1;i<=q;i++){
		ch=getchar();
		while(ch<='x'&&ch>='a')t[i][0]+=ch,ch=getchar();
		ch=getchar();
		while(ch<='x'&&ch>='a')t[i][1]+=ch,ch=getchar();
		cnt+=t[i][0].size()+t[i][1].size();
	}
	if(n<=1000&&q<=1000&&cnt<=4000){
		po[0]=1;
		for(int i=1;i<=n;i++)po[i]=po[i-1]*p;
		for(int i=1;i<=n;i++){
			for(int j=(int)s[i][0].size()-1;j>=0;j--)hasha[i][0]=hasha[i][0]*p+s[i][0][j]-'a'+1;
			for(int j=(int)s[i][1].size()-1;j>=0;j--)hasha[i][1]=hasha[i][1]*p+s[i][1][j]-'a'+1;
//			printf("%lld %lld\n",hasha[i][0],hasha[i][1]);
		}
//		printf("				%lld\n",hasha[3][1]);
		for(int i=1;i<=q;i++){
			hashb[0][t[i][0].size()]=hashb[1][t[i][1].size()]=0;
			for(int j=(int)t[i][0].size()-1;j>=0;j--)hashb[0][j]=hashb[0][j+1]*p+t[i][0][j]-'a'+1;
//			for(int j=0;j<t[i][0].size();j++)printf("%lld ",hashb[0][j]);
//			printf("\n");
			for(int j=(int)t[i][1].size()-1;j>=0;j--)hashb[1][j]=hashb[1][j+1]*p+t[i][1][j]-'a'+1;
//			for(int j=0;j<t[i][1].size();j++)printf("%lld ",hashb[1][j]);
//			printf("\n");
			int ans=0;
			for(int j=-1;j<(int)t[i][0].size();j++){
				if(hashb[0][0]-hashb[0][j+1]*po[j+1]==hashb[1][0]-hashb[1][j+1]*po[j+1]){
//					printf("%d:\n",j);
					for(int k=1;k<=n;k++){
						int len=s[k][0].size();
						if(j+len>=t[i][0].size())continue;
//						printf("%d %lld %lld %lld %lld %lld %lld\n", k , hashb[0][j+1]-hashb[0][j+len+1]*po[len] , hasha[k][0] , hashb[1][j+1]-hashb[1][j+len+1]*po[len] , hasha[k][1] , hashb[0][j+len+1] , hashb[1][j+len+1]);
						if(hashb[0][j+1]-hashb[0][j+len+1]*po[len]==hasha[k][0]&&hashb[1][j+1]-hashb[1][j+len+1]*po[len]==hasha[k][1]&&hashb[0][j+len+1]==hashb[1][j+len+1])ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i][0].size();j++)if(s[i][0][j]=='b')ca[i][0]=j+1;
			for(int j=0;j<s[i][1].size();j++)if(s[i][1][j]=='b')ca[i][1]=j+1;
			a[ca[i][1]-ca[i][0]+N].push_back(i);
		}
		for(int i=1;i<=q;i++){
			for(int j=0;j<t[i][0].size();j++)if(t[i][0][j]=='b')cb[i][0]=j+1;
			for(int j=0;j<t[i][1].size();j++)if(t[i][1][j]=='b')cb[i][1]=j+1;
			int q=cb[i][1]-cb[i][0]+N,ans=0;
			for(int j=0;j<a[q].size();j++){
				int l=ca[a[q][j]][0],r=ca[a[q][j]][1],len1=s[a[q][j]][0].size(),len2=s[a[q][j]][1].size();
				if(len1-l<=t[i][0].size()-cb[i][0]&&l<=cb[i][0]&&len2-r<=t[i][1].size()-cb[i][1]&&r<=cb[i][1])ans++;
			}
			printf("%d\n",ans);
		}
	}
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/