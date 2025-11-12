#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
long long res=0;
string s1[N],s2[N];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++) cin>>s1[i]>>s2[i];
	for(int I=1; I<=q; I++)
	{
		res=0;
		cin>>t1>>t2;
		for(int i=1; i<=n; i++)
		{
			string T1=t1,T2=t2;
	 		while(T1.find(s1[i])!=string::npos)
	 		{
	 			int pos=T1.find(s1[i]);
	 			string t1_=T1;
	 			t1_=t1_.replace(pos,s1[i].size(),s2[i]);
	 			if(t1_==t2)
				{
					res++;
					break;
				}
	 			else T1=T1.replace(pos,s1[i].size(),"$$");
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
