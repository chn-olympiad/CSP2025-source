#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
map<int,char>s1[N];
map<int,char>s2[N];
map<pair<string,int>,int>th;
map<string,int>len;
string mbi[N];
int z[N],y[N];//z[i]表示 i替换的左端点-1，y[i]同理。 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;scanf("%d%d",&n,&q);
	memset(z,-1,sizeof(z));memset(y,-1,sizeof(y));
	th.clear();len.clear();
	for(int i=1;i<=n;i++){
		char x[M],p[M];scanf("%s%s",x+1,p+1);
		for(int j=1;j<=strlen(x+1);j++)s1[i][j]=x[j],s2[i][j]=p[j]; 
		string dif="";mbi[i]="";
		for(int j=1;j<=strlen(x+1);j++){
			if(x[j]!=p[j]){
				if(z[i]==-1)z[i]=j-1;
				dif+=x[j];
				mbi[i]+=p[j];
			}
			else if(z[i]!=-1&&y[i]==-1)y[i]=j;
		}
		if(y[i]==-1)y[i]=strlen(x+1)+1;
		th[{dif,++len[dif]}]=i;
	}
	while(q--){
		char t1[N],t2[N];scanf("%s%s",t1+1,t2+1);
		if(strlen(t1+1)!=strlen(t2+1)){
			printf("0\n");continue;
		}
		string dif="",mb="";
		int l=-1,r=-1;
		for(int i=1;i<=strlen(t1+1);i++){
			if(t1[i]!=t2[i]){
				if(l==-1)l=i-1;
				dif+=t1[i];
				mb+=t2[i];
			}
			else if(l!=-1&&r==-1)r=i;
		}
		if(r==-1)r=strlen(t1+1)+1;
		if(len[dif]==0){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=len[dif];i++){//l,r为被替换的字符串，z,y为替换字符串 
			int k=th[{dif,i}];//k号字符串 
			if((l<z[k])||(strlen(t1+1)-r)-(s1[k].size()-y[k])<0)continue;
			if(mbi[k]!=mb)continue;
			bool flag=1;
			for(int j=1;j<=z[k]&&flag;j++)if(s1[k][j]!=t1[l-z[k]+j])flag=0;
			for(int j=y[k];j<=s1[k].size()&&flag;j++)if(s1[k][j]!=t1[r+(j-y[k])])flag=0;
			if(flag)ans++;	
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
