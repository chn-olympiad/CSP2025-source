#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool fl;
int n,q,ans,ls[N],lt,id1[N],id2[N],idd1,idd2;
char s1[N],s2[N],t1[N],t2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		ls[i]=strlen(s1+1);
		for(int j=1;j<=ls[i];j++){
			if((s1[j]!='a'&&s1[j]!='b')||(s2[j]!='a'&&s2[j]!='b')){
				fl=1;
			}
			if(s1[j]=='b'){
				if(id1[i]) fl=1;
				else id1[i]=j;
			}
			if(s2[j]=='b'){
				if(id2[i]) fl=1;
				else id2[i]=j;
			}
		}
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		lt=strlen(t1+1);
		if(lt!=strlen(t2+1)){
			printf("0\n");
			continue;
		}
		idd1=idd2=ans=0;
		for(int i=1;i<=lt;i++){
			if((t1[i]!='a'&&t1[i]!='b')||(t2[i]!='a'&&t2[i]!='b')) fl=1;
			if(t1[i]=='b'){
				if(idd1) fl=1;
				else idd1=i;
			}
			if(t2[i]=='b'){
				if(idd2) fl=1;
				else idd2=i;
			}
		}
		if(!fl){
			for(int i=1;i<=n;i++){
				if(id1[i]-id2[i]==idd1-idd2&&idd1>=id1[i]&&lt-idd2>=ls[i]-id2[i]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
