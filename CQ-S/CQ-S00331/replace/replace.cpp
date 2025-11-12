#include<bits/stdc++.h>
using namespace std;
long long n,q,ADD[10050000];
string S1[205000],S2[205000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=0;i<n;i++)
	{
		cin>>S1[i]>>S2[i];
		long long B1,B2;
		for(long long j=0;j<S1[i].size();j++)
		{
			if(S1[i][j]=='b')B1=j;
			if(S2[i][j]=='b')B2=j;
		}
		ADD[5000000+B1-B2]++;
//		cout<<5000000+B1-B2<<endl;
	}
	for(long long i=0;i<q;i++)
	{
		long long ans=0;
		string T1,T2;
		cin>>T1>>T2;
		long long B1,B2;
		for(long long j=0;j<T1.size();j++)
		{
			if(T1[j]=='b')B1=j;
			if(T2[j]=='b')B2=j;
		}
		printf("%lld\n",ADD[5000000+B1-B2]);
//		cout<<"cout"<<5000000+B1-B2<<endl;
	}
	return 0;
}
