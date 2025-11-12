#include <bits/stdc++.h>
#define wi wk[i]
#define wx wk[i].mx
#define wd wk[i].md
#define wn wk[i].mn
using namespace std;

long long t,n,cpn[4][100005],nn[4],d,ans;
long long dp[100005];
struct wkr
{
	long long a;long long b;long long c;
	int mx,md,mn,ga;long long maxx,midd,minn;
} wk[100005];

bool cmp(wkr x1,wkr x2)
{
	long long max1=max(x1.a,max(x1.b,x1.c)),max2=max(x2.a,max(x2.b,x2.c));
	long long min1=min(x1.a,min(x1.b,x1.c)),min2=min(x2.a,min(x2.b,x2.c));
	long long mid1=x1.a+x1.b+x1.c-max1-min1,mid2=x2.a+x2.b+x2.c-max2-min2;
//	cout<<x1.a<<" "<<x1.b<<" "<<x1.c<<" "<<max1<<" "<<mid1<<" "<<min1<<endl;
//	cout<<x2.a<<" "<<x2.b<<" "<<x2.c<<" "<<max2<<" "<<mid2<<" "<<min2<<endl;
	if (max1==max2)
	{
		if (mid1==mid2)
		{
			return min1>min2;
		}
		else return mid1>mid2;
	}
	else return max1>max2;
}

long long ft(int number,int idx)
{
	
	//cout<<wk[idx].a<<" "<<wk[idx].b<<" "<<wk[idx].c<<" had a fight.\n";
	long long rtn=0,besti=0,bestrst=0;
	if (number==1)//max
	{
		for (int i=1;i<idx;i++)
		{
			if (wi.ga==wk[idx].mx)//meet competer
			{
				if (wi.ga==wi.mx)//competer is at max as well 
				{
					long long temprtn=wk[idx].maxx-wi.maxx;
					if (nn[wi.md]<d) {temprtn+=wi.midd;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=2;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to md
					else if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else if (wi.ga==wi.md)//competer is at mid 
				{
					long long temprtn=wk[idx].maxx-wi.midd;
					if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else
				{
					long long temprtn=wk[idx].maxx-wi.minn;
					if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
			} 
		}
	}
	
	else if (number==2)//mid
	{
		for (int i=1;i<idx;i++)
		{
			if (wi.ga==wk[idx].md)//meet competer
			{
				if (wi.ga==wi.mx)//competer is at max 
				{
					long long temprtn=wk[idx].midd-wi.maxx;//cout<<i<<" "<<idx<<" "<<temprtn<<endl;
					if (nn[wi.md]<d) {temprtn+=wi.midd;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=2;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to md
					else if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else if (wi.ga==wi.md)//competer is at mid 
				{
					long long temprtn=wk[idx].midd-wi.midd;
					if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else
				{
					long long temprtn=wk[idx].midd-wi.minn;
					if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
			} 
		}
	}
	
	else//min
	{
		
		for (int i=1;i<idx;i++)
		{
			if (wi.ga==wk[idx].mn)//meet competer
			{
				if (wi.ga==wi.mx)//competer is at max 
				{
					long long temprtn=wk[idx].minn-wi.maxx;//cout<<i<<" "<<idx<<" "<<temprtn<<endl;
					if (nn[wi.md]<d) {temprtn+=wi.midd;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=2;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to md
					else if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else if (wi.ga==wi.md)//competer is at mid 
				{
					long long temprtn=wk[idx].minn-wi.midd;
					if (nn[wi.mn]<d) {temprtn+=wi.minn;if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=1;/*cout<<wi.a<<" "<<wi.b<<" "<<wi.c<<" has gone to "<<wi.ga<<endl;*/}}//cmpt to mn
					else if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
				else
				{
					long long temprtn=wk[idx].minn-wi.minn;
					if (temprtn>rtn) {rtn=temprtn;besti=i;bestrst=0;}
				}
			} 
		}
	}
	
	nn[wk[besti].ga]--;wk[besti].ga=bestrst;nn[bestrst]++;
	
	return rtn;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&wk[i].a,&wk[i].b,&wk[i].c);
			if (wk[i].a>=wk[i].b&&wk[i].b>=wk[i].c){wk[i].mx=1;wk[i].md=2;wk[i].mn=3;}
			else if (wk[i].a>=wk[i].c&&wk[i].c>=wk[i].b){wk[i].mx=1;wk[i].md=3;wk[i].mn=3;}
			else if (wk[i].b>=wk[i].a&&wk[i].a>=wk[i].c){wk[i].mx=2;wk[i].md=1;wk[i].mn=3;}
			else if (wk[i].b>=wk[i].c&&wk[i].c>=wk[i].a){wk[i].mx=2;wk[i].md=3;wk[i].mn=1;}
			else if (wk[i].c>=wk[i].a&&wk[i].a>=wk[i].b){wk[i].mx=3;wk[i].md=1;wk[i].mn=2;}
			else {wk[i].mx=3;wk[i].md=2;wk[i].mn=1;}
			wk[i].maxx=max(wk[i].a,max(wk[i].b,wk[i].c));
			wk[i].minn=min(wk[i].a,min(wk[i].b,wk[i].c));
			wk[i].midd=wk[i].a+wk[i].b+wk[i].c-wk[i].maxx-wk[i].minn;
		}
		sort(wk+1,wk+1+n,cmp);
		nn[1]=0;nn[2]=0;nn[3]=0;d=n>>1;ans=0;
		
//		cout<<"After sorting\n";//DEBUG
//		for (int i=1;i<=n;i++) cout<<wi.maxx<<" "<<wi.midd<<" "<<wi.minn<<endl;//DEBUG
		
		for (int i=1;i<=n;i++)
		{
			
			if (nn[wk[i].mx]<d)//max is ok
			{
				nn[wk[i].mx]++;wi.ga=wi.mx;
				if (wk[i].mx==1) ans+=wk[i].a;
				if (wk[i].mx==2) ans+=wk[i].b;
				if (wk[i].mx==3) ans+=wk[i].c;
			}
			else 
			{
				long long rst=ft(1,i);//use its max to fight
				if (rst)
				{
					ans+=rst;nn[wk[i].mx]++;
//					cout<<rst<<"| "<<wi.a<<" "<<wi.b<<" "<<wi.c<<" finally wins.\n";
				}
				else
				{
					if (nn[wk[i].md]<d)//mid is ok
					{
//					cout<<wk[i].a<<" "<<wk[i].b<<" "<<wk[i].c<<" to "<<wk[i].md<<endl;
						nn[wk[i].md]++;wi.ga=wi.md;
						if (wk[i].md==1) ans+=wk[i].a;
						if (wk[i].md==2) ans+=wk[i].b;
						if (wk[i].md==3) ans+=wk[i].c;
					}
					else
					{
						long long rst=ft(2,i);//use its mid to fight
						if (rst)
						{
							ans+=rst;nn[wk[i].md]++;
	//						cout<<rst<<"| "<<wi.a<<" "<<wi.b<<" "<<wi.c<<" finally wins.\n";
						}
						else
						{
							if (nn[wk[i].mn]<d)//min is ok
							{
		//						cout<<wk[i].a<<" "<<wk[i].b<<" "<<wk[i].c<<" to "<<wk[i].mn<<endl;
								nn[wk[i].mn]++;wi.ga=wi.mn;
								if (wk[i].mn==1) ans+=wk[i].a;
								if (wk[i].mn==2) ans+=wk[i].b;
								if (wk[i].mn==3) ans+=wk[i].c;
							}
							else
							{
								long long rst=ft(3,i);//use its min to fight
								if (rst)
								{
									ans+=rst;nn[wk[i].mn]++;
			//						cout<<rst<<"| "<<wi.a<<" "<<wi.b<<" "<<wi.c<<" finally wins.\n";
								}
								else ans=ans;//homeless
							}
						}
					}
					
				}
				
			}
//			cout<<"i="<<i<<" ans="<<ans<<endl;
		}
		
		
		printf("%lld\n",ans);
	}
	

	return 0;
}

