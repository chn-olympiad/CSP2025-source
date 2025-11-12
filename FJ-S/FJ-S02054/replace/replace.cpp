#include<stdio.h>
#include<string.h>
int s[200005][2],d[200005][2];
char t0[3000005],t1[3000005],t2[3000005];
char s0[3000005],s1[3000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s0);
		int j=0;
		while(s0[j]!='b')j++;
		s[i][0]=j;
		while(s0[j]!=0)j++;
		s[i][1]=j-s[i][0]-1;
		scanf("%s",s0);
		j=0;
		while(s0[j]!='b')j++;
		d[i][0]=j;
		while(s0[j]!=0)j++;
		d[i][1]=j-d[i][0]-1;
	}
	for(int i=1;i<=q;i++){
		scanf("%s %s",t0,t1);
		int ans=0;
		for(int j=1;j<=n;j++){
			int k=0;
			for(;k<s[j][0];k++)s0[k]='a';
			s0[k]='b';
			k++;
			int o=0;
			for(;o<s[j][1];o++)s0[k+o]='a';
			s0[k+o]='\0';
			
			k=0;
			for(;k<d[j][0];k++)s1[k]='a';
			s1[k]='b';
			k++;
			o=0;
			for(;o<d[j][1];o++)s1[k+o]='a';
			s1[k+o]='\0';
			if(strlen(s0)==1||strlen(s0)>strlen(t0))continue;
			if(strstr(t0,s0)!=0){
				char* inx=strstr(t0,s0);
				int iinx=(inx-t0);
				for(int i=0;t0[i]!=0;i++)t2[i]=t0[i];
				for(int i=iinx;s0[i]!=0;i++){
					t0[i]=s1[i];
				}
				if(strcmp(t0,t1)==0)ans++;
				for(int i=0;t2[i]!=0;i++)t0[i]=t2[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}