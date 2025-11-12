#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300000,M=6000000;
int n,q,m,l,r,l1[N],l4[N],ans;
unsigned long long s1[N],s2[N],s3[N],s4[N],t1[M],t2,t3,t4[M];
char c1[M],c2[M];
void Get(){
	for(int j=1;j<=m;j++){
		if(c1[j]!=c2[j]){
			l=j;
			break;
		}
	}
	for(int j=m;j>=1;j--){
		if(c1[j]!=c2[j]){
			r=j;
			break;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",c1+1,c2+1);
		m=strlen(c1+1);
		Get();
		l1[i]=l-1;
		for(int j=l-1;j>=1;j--)s1[i]=s1[i]*13331+c1[j];
		for(int j=l;j<=r;j++)s2[i]=s2[i]*13331+c1[j];
		for(int j=l;j<=r;j++)s3[i]=s3[i]*13331+c2[j];
		l4[i]=m-r;
		for(int j=r+1;j<=m;j++)s4[i]=s4[i]*13331+c1[j];
		//cout<<s1[i]<<' '<<s2[i]<<' '<<s3[i]<<' '<<s4[i]<<endl;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",c1+1,c2+1);
		m=strlen(c1+1);
		Get();
		for(int j=l-1;j>=1;j--)t1[l-j]=t1[l-j-1]*13331+c1[j];
		t2=t3=0;
		for(int j=l;j<=r;j++)t2=t2*13331+c1[j];
		for(int j=l;j<=r;j++)t3=t3*13331+c2[j];
		for(int j=r+1;j<=m;j++)t4[j-r]=t4[j-r-1]*13331+c1[j];
		ans=0;
		/*for(int j=1;j<=l-1;j++)cout<<t1[j]<<' ';
		cout<<endl;
		for(int j=1;j<=m-r;j++)cout<<t4[j]<<' ';
		cout<<endl;*/
		for(int j=1;j<=n;j++){
			if(l1[j]>l-1||l4[j]>m-r)continue;
			//cout<<(s2[j]==t2)<<' '<<(s3[j]==t3)<<' '<<(s1[j]==t1[l1[j]])<<' '<<(s4[j]==t4[l4[j]])<<endl;
			//cout<<t1[l1[j]]<<' '<<t4[l4[j]]<<' '<<l1[j]<<' '<<l4[j]<<endl;
			if(s2[j]==t2&&s3[j]==t3&&s1[j]==t1[l1[j]]&&s4[j]==t4[l4[j]])ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
