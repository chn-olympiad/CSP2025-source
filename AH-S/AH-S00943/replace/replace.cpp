#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,q;
ull s1[5000005][2],s2[5000005][2],fac[5000005]={1};
map<ull,map<ull,int>>mp;
char ch1[5000005],ch2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf ("%d%d",&n,&q);
	for (int i=1;i<=5000000;i++)fac[i]=fac[i-1]*27;
	for (int i=1;i<=n;i++){
		scanf ("%s%s",ch1+1,ch2+1);
		ull sum1=0,sum2=0;
		int len1=strlen(ch1+1),len2=strlen(ch2+1);
		for (int i=1;i<=len1;i++)sum1=sum1*27+(ch1[i]-'a'+1)*27;
		for (int i=1;i<=len2;i++)sum2=sum2*27+(ch2[i]-'a'+1)*27;
		mp[sum1][sum2]++;
		//printf ("%llu %llu\n",sum1,sum2);
	}
	while (q--){
		scanf ("%s%s",ch1+1,ch2+1);
		int len1=strlen(ch1+1),len2=strlen(ch2+1),len=0,ans=0;
		if (len1!=len2){puts("0");continue;}
		len=len1;
		for (int i=1;i<=len;i++)s1[i][0]=s1[i-1][0]*27+(ch1[i]-'a'+1)*27;
		for (int i=1;i<=len;i++)s2[i][0]=s2[i-1][0]*27+(ch2[i]-'a'+1)*27;
		s1[len+1][0]=s2[len+1][0]=s1[len+1][1]=s2[len+1][1]=0;
		for (int i=len;i>=1;i--)s1[i][1]=s1[i+1][1]*27+(ch1[i]-'a'+1)*27;
		for (int i=len;i>=1;i--)s2[i][1]=s2[i+1][1]*27+(ch2[i]-'a'+1)*27;
		int ll=1,rr=len;
		for (int i=1;i<=len;i++)if (ch1[i]!=ch2[i]){ll=i;break;}
		for (int i=len;i>=1;i--)if (ch1[i]!=ch2[i]){rr=i;break;}
		for (int i=ll;i>=1;i--)
			for (int j=rr;j<=len;j++)
				//if (mp[s1[j][0]-s1[i-1][0]*fac[j-i+1]]==s2[j][0]-s2[i-1][0]*fac[j-i+1]){
					ans+=mp[s1[j][0]-s1[i-1][0]*fac[j-i+1]][s2[j][0]-s2[i-1][0]*fac[j-i+1]];
					//printf ("%d ",mp1[s1[j][0]-s1[i-1][0]*fac[j-i+1]]);
				//printf ("%d %d !%llu %llu\n",i,j,s1[j][0]-s1[i-1][0]*fac[j-i+1],s2[j][0]-s2[i-1][0]*fac[j-i+1]);
			//}
		printf ("%d\n",ans);
	}
	return 0;
}
