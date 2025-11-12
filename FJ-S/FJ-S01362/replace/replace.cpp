#include<bits/stdc++.h>
using namespace std; 
const int LL=2e6+7;
int N,Q;
int s[LL];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		s[i]=s1.find('b')-s2.find('b');
	}
	for(int i=1;i<=Q;i++)
	{
		int Ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=N;i++)
			if(s1.find('b')-s2.find('b')==s[i])
				Ans++;
		printf("%d\n",Ans);
	}
	return 0;
}
