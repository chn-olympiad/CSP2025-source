#include<bits/stdc++.h>
using namespace std;
long long const N=1e5+5;
long long n,m,sum;
long long knd[3];
struct club{
	long long a,b,c,nd;
	long long max,cmax;
	long long ex;
}cl[N];
long long cmp(club a,club b){
	if(a.max!=b.max)
		return a.max>b.max;
	else
		return a.cmax>b.cmax;
}
long long cmp2(club a,club b){
	return a.ex>b.ex;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //ios::sync_stdio(0);
    //cin.tie();
    //cout.tie();
    scanf("%lld",&m);
    while(m--){
		scanf("%lld",&n);
		long long up=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&cl[i].a,&cl[i].b,&cl[i].c);
			cl[i].max=max(max(cl[i].a,cl[i].b),cl[i].c);
			if(cl[i].max==cl[i].a) cl[i].nd=1,cl[i].cmax=max(cl[i].b,cl[i].c);
			if(cl[i].max==cl[i].b) cl[i].nd=2,cl[i].cmax=max(cl[i].a,cl[i].c);
			if(cl[i].max==cl[i].c) cl[i].nd=3,cl[i].cmax=max(cl[i].a,cl[i].c);
			cl[i].ex=cl[i].max-cl[i].cmax;
		}
		sort(cl+1,cl+n+1,cmp2);
		long long _max=0;
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(flag){
				_max+=cl[i].cmax;
				continue;
			}
			_max+=cl[i].max;
			knd[cl[i].nd]++;
			for(int j=1;j<=3;j++)
				if(knd[j]==up)
				flag=1;

		}
		cout<<_max<<"\n";
		memset(cl,0,sizeof cl);
		memset(knd,0,sizeof knd);
	}
}
