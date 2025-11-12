#include<bits/stdc++.h>
using namespace std;
#define N 998244353LL
int l[500];
int Outs[500];
long long S,S1;int n;
void f(int L,int d,int R,int O)
{
	while(d>=0&&l[d]<=0) d--;
	//printf("%d,%d,%d,%d\n",L,d,R,O);
	if(d==-1)
	{
		if(R<1) S1+=L;
		S1%=N;
		return;
	}
	l[d]--;
	f((long long)L*(n-Outs[d]-O-1)%N,d,R-1,O+1);
	f((long long)L*O%N,d,R,O);
	l[d]++;
}

int main()
{
	//freopen("employ2.in","r",stdin);
	//freopen("employ2.out","w",stdout);
	int len=0;
	int k,Survivors=0;char c;
	S=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;)
	{
		scanf("%c",&c);
		if(c=='0') 
		{
			Outs[len++]=i;
		}
		S*=++i;
		S%=N;
	}
	for(int i=n;i--;)
	{
		int a;
		scanf("%d",&a);
		if(len<a) Survivors++;
		else l[a]++;
	}
	f(1,len,n-k-len,1);//Remainning Outs By Giving Up
	while(Survivors)
	{
		S1*=Survivors--;
		S1%=N;
	}
	if(S<S1) cout<<0;
	else cout<<S-S1;
	return 0;
}
