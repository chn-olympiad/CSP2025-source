//GZ-S00430 毕节七星关东辰实验学校 赵锡元
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
ll n,t,k,bend,need[200860],bigg,anss;
ll viss[2000860],ru1,ru2,ru3,ru4;
ll order[2000860],have[2000860];

int cha1(ll a)
{
	//cout<<"->"<<order[a]<<" "<<a<<endl;
	if(order[a]!=a)
	{
		order[a]=cha1(order[a]);
		return order[a];
	}
	else
	{
		return a;
	}
}
void jia(ll a,ll b)
{
	//ll a1=cha1(a),b1=cha1(b);
	//cout<<"@@";
	order[a]=order[b];
	have[b]+=have[a];
	if(have[b]>bigg)bigg=have[b];
}
struct qp
{
	ll a,b,now,ce;
}bian[2000860];
bool bi(qp a,qp b)
{
	return a.ce<b.ce;
}
void add_bian(ll a,ll b,ll c,ll d)
{
		bian[++bend].a=a;
		bian[bend].b=b;
		bian[bend].ce=c;
		bian[bend].now=d;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>t>>k;
	for(int ww=1;ww<=t;ww++)
	{
		//cout<<"i";
		cin>>ru1>>ru2>>ru3;
		
		add_bian(ru1,ru2,ru3,0);
		
	}
	
	for(int ww=1;ww<=k;ww++)
	{
		cin>>need[ww];
		for(int i=1;i<=n;i++)
		{
			cin>>ru1;
			add_bian(n+ww,i,ru1,ww);
		}
	}
	for(int i=0;i<=n+12;i++)
	{
		order[i]=i;
		if(i<=n)have[i]=1;
	}
	sort(bian+1,bian+bend+1,bi);
	anss=0;
	for(int i=1;i<=bend&&bigg<n;i++)
	{
		
		ll a1=cha1(bian[i].a),b1=cha1(bian[i].b);
		//cout<<a1<<"<->"<<b1<<endl;
		if(a1!=b1)
		{
			jia(a1,b1);
			anss+=bian[i].ce;
		}
	}
	
	cout<<anss;
	return 0;
}
