#include<bits/stdc++.h>
using namespace std;
long long n,q,i,j,k;
char a[5000005],b[5000005];
unsigned long long s1,s2,d=13331;
unsigned long long sum[5000005],sum2[5000005],pw[5000005];
map<pair<unsigned long long,unsigned long long>,long long> s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%s",a+1);
		scanf("%s",b+1);
		s1=0;s2=0;
		long long len=strlen(a+1);
		for(j=1;j<=len;j++){
			s1=s1*d+a[j];
		}
		for(j=1;j<=len;j++){
			s2=s2*d+b[j];
		}
		s[make_pair(s1,s2)]++;
	}
	for(i=1;i<=q;i++){
		scanf("%s",a+1);
		scanf("%s",b+1);
		long long len=strlen(a+1),len2=strlen(b+1);
		if(len!=len2){
			printf("0\n");
			continue;
		}
		long long id1=0,id2=0;
		for(j=1;j<=len;j++){
			if(a[j]!=b[j]){
				id1=j;
				break;
			}
		}
		for(j=len;j>=1;j--){
			if(a[j]!=b[j]){
				id2=j;
				break;
			}
		}
		pw[0]=1;
		for(j=1;j<=len;j++){
			pw[j]=pw[j-1]*d;
			sum[j]=sum[j-1]*d+a[j];
			sum2[j]=sum2[j-1]*d+b[j];
		}
		long long ans=0;
		for(j=1;j<=id1;j++){
			for(k=id2;k<=len;k++){
				unsigned long long ox=sum[k]-sum[j-1]*pw[k-j+1];
				unsigned long long px=sum2[k]-sum2[j-1]*pw[k-j+1];
				ans+=s[make_pair(ox,px)];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
