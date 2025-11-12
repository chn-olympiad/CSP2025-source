 #include<bits/stdc++.h>
 const int P=27;
 using namespace std;
 unsigned long long hah1[200005],hah2[200005],hah[5000005],ha,p[5000005];
 int n,q,len[200005];
 long long ans;
 char s1[5000005],s2[5000005];
 int main()
 {
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
 	p[0]=1;
 	for(int i=1;i<=5000000;i++)
 	{
 		p[i]=p[i-1]*P;
	 }
 	scanf("%d%d",&n,&q);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%s",s1);
 		scanf("%s",s2);
 		len[i]=strlen(s1);
 		for(int j=0;j<len[i];j++)
 		{
 			hah1[i]=hah1[i]*P+s1[j]-'a'+1;
 			hah2[i]=hah2[i]*P+s2[j]-'a'+1;
		 }
	 }
	for(int i=1;i<=q;i++)
	{
		ans=0;
		scanf("%s",s1);
		scanf("%s",s2);
		if(strlen(s1)!=strlen(s2))
		{
			printf("0\n");
			continue;
		}
		ha=0;
		int l=strlen(s1);
		for(int j=1;j<=l;j++)
		{
			hah[j]=hah[j-1]*P+s1[j-1]-'a'+1;
			ha=ha*P+s2[j-1]-'a'+1;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=len[j];k<=l;k++)
			{
				if(hah[k]-hah[k-len[j]]*p[len[j]]==hah1[j])
				{
					if(hah[k-len[j]]*p[l+len[j]-k]+hah2[j]*p[l-k]+hah[l]-hah[k]*p[l-k]==ha)
						ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
 	return 0;
 }
