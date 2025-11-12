#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
const int N=100005;
int n;
struct node{
	int a,b,c;
}T[N];
int tag[N],ct[5];
int stk[N],top;
int res;
int p;
void mian()
{
	res=top=0;
	ct[1]=ct[2]=ct[3]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,c,t;
		scanf("%d%d%d",&a,&b,&c);
		t=max(a,max(b,c));
		if(t==a) tag[i]=1,ct[1]++;
		else if(t==b) tag[i]=2,ct[2]++;
		else if(t==c) tag[i]=3,ct[3]++;
		res+=t;
		T[i]=(node){a,b,c};
	}
	p=1;
	if(ct[2]>ct[p]) p=2;
	if(ct[3]>ct[p]) p=3;
	if(ct[p]>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			if(tag[i]^p) continue;
			int a=T[i].a,b=T[i].b,c=T[i].c,t;
			if(p==1) t=max(b,c);
			if(p==2) t=max(a,c);
			if(p==3) t=max(a,b);
			stk[++top]=max(max(a,b),c)-t;
		}
		sort(stk+1,stk+1+top);
		for(int i=1;i<=ct[p]-n/2;i++) res-=stk[i];
	}
	printf("%d\n",res);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int T;
	scanf("%d",&T);
	while(T--) mian();
	return 0;
} 
