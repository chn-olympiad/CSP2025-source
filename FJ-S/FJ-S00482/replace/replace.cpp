#include<bits/stdc++.h>
using namespace std;
int n,q;
//char t1[205][205], t2[205][205];
char s1[2500006],s2[2500006],s[5000006];
int ch[2000006][26], fa[2000006][21], dep[2000006], w[2000006], w2[2000006]; int T1=1;

void zzp_Ins(char *s,int len,bool flag){
	int p=1;
	for (int i=1;i<=len;i++){
		int c=s[i]-'a';
		if (ch[p][c]) p=ch[p][c];
		else p=ch[p][c]=++T1, dep[p]=i;
//		printf("Ins: i,p,T1,c=%d,%d,%d,%d>\n",i,p,T1,c);
	}
//	puts("Ins: End");
	w[p]++;
	if (flag) w2[p]++;
	return ;
}

queue<int> zq;
void zzp_Build(){
	for (int c=0;c<=25;c++) ch[0][c]=1; zq.push(1); 
	while (!zq.empty()){
		int u=zq.front(); zq.pop();
		w[u]+=w[fa[u][0]]; w2[u]+=w2[fa[u][0]];
		for (int c=0;c<=25;c++){
			if (ch[u][c]) zq.push(ch[u][c]),fa[ch[u][c]][0]=ch[fa[u][0]][c];
			else ch[u][c]=ch[fa[u][0]][c];
		}
	}
//	for (int i=1;i<=T1;i++) printf("Build: fa[%d][0]=%d>\n",i,fa[i][0]);
	for (int i=2;i<=T1;i++)
		for (int j=1;j<=20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
	return ;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		bool flag=1;
		for (int j=1;j<=len;j++)
			s[j*2-1]=s1[j], s[j*2]=s2[j], flag&=(s1[j]==s2[j]);
		zzp_Ins(s,len*2,flag);
	}
	zzp_Build();
	for (int i=1;i<=q;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		for (int j=1;j<=len;j++)
			s[j*2-1]=s1[j], s[j*2]=s2[j];
		int L,R;
		for (L=1;s1[L]==s2[L];L++); 
		for (R=len;s1[R]==s2[R];R--);
		int p=1; long long ans=0;
		for (int j=1;j<=len*2;j++){
			p=ch[p][s[j]-'a'];
//			printf("Find: i,j,p(dep[p]),L,R=%d,%d,%d(%d),%d,%d>\n",i,j,p,dep[p],L,R);
			if (j%2==0&&j/2>=R&&dep[p]>=(j/2-L+1)*2){
				int t=p;
				for (int x=20;x>=0;x--)
					if (dep[fa[t][x]]>=(j/2-L+1)*2) t=fa[t][x];
				t=fa[t][0];
				ans+=w[p]-w[t];
//				printf("> Jump: t=%d>\n",t);
			}
//			if (j%2==0) ans+=w2[p];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
