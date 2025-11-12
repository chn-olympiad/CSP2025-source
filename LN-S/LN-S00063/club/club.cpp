#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,maxx,cnta,cntb,cntc;
long long val,ans,ansa,ansb,ansc;
struct choice
{
    int a,b,c;
}d[maxn];
bool cmpa(choice x,choice y)
{
    return x.a>y.a;
}
bool cmpb(choice x,choice y)
{
    return x.b>y.b;
}
bool cmpc(choice x,choice y)
{
    return x.c>y.c;
}
int cmp(int i,int j,int k)
{
    if(max(max(i,j),k)==i){
        cnta++;
        return i;
    }
    else if(max(max(i,j),k)==j){
        cntb++;
        return j;
    }
    else{
        cntc++;
        return k;
    }
}
void solvea()
{
	int altb[maxn],altc[maxn];
    sort(d+1,d+n+1,cmpa);
    for(int i=1;i<=n/2;i++)ansa+=d[i].a;
    for(int i=n/2+1;i<=n;i++)
    {
            altb[i]=d[i].b;
            altc[i]=d[i].c;
            ansa+=max(altb[i],altc[i]);
    }
}
void solveb()
{
	int alta[maxn],altc[maxn];
    sort(d+1,d+n+1,cmpb);
    for(int i=1;i<=n/2;i++)ansb+=d[i].b;
    for(int i=n/2+1;i<=n;i++)
    {
            alta[i]=d[i].a;
            altc[i]=d[i].c;
            ansb+=max(alta[i],altc[i]);
    }
}
void solvec()
{
	int alta[maxn],altb[maxn];
    sort(d+1,d+n+1,cmpc);
    for(int i=1;i<=n/2;i++)ansc+=d[i].c;
    for(int i=n/2+1;i<=n;i++)
    {
            alta[i]=d[i].a;
            altb[i]=d[i].b;
            ansc+=max(alta[i],altb[i]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
    	cnta=0,cntb=0,cntc=0,ansa=0,ansb=0,ansc=0,ans=0;
    	val=0;
    	memset(d,0,sizeof(d));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
        for(int i=1;i<=n;i++) val+=cmp(d[i].a,d[i].b,d[i].c);
        if(max(max(cnta,cntb),cntc)<=n/2)cout<<val<<endl;
        else
        {
		solvea();
		solveb();
		solvec();
		ans=max(ansa,max(ansb,ansc));
		cout<<ans<<endl;
        }
    }
    return 0;
}

