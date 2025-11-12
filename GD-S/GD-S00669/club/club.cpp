#include<bits/stdc++.h>
using namespace std;
#define FOR_R(i,a,b)	for(int i=a;i<=b;i++)
#define pii pair<long long,long long>
const int N=100010;
struct P{
	long long a,b,c;
}e[N];
int sa,sb,sc,ans,t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		priority_queue<pii,vector<pii> >qa;
		priority_queue<pii,vector<pii> >qb;
		priority_queue<pii,vector<pii> >qc;
		cin>>n;
		memset(e,0,sizeof(e));
		sa=0;sb=0;sc=0;ans=0;
		FOR_R(i,1,n)	{
			int bz1=0,bz2=0,bz3=0;
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c)	{
				sa++;
				qa.push({max(e[i].c,e[i].b)-e[i].a,i});
				ans+=e[i].a;
			}
			else if(e[i].b>=e[i].a&&e[i].b>=e[i].c)	{
				sb++;
				qb.push({max(e[i].c,e[i].a)-e[i].b,i});
				ans+=e[i].b;
			}
			else if(e[i].c>=e[i].a&&e[i].c>=e[i].b)	{
				sc++;
				qc.push({max(e[i].a,e[i].b)-e[i].c,i});
				ans+=e[i].c;
			}
		}
		if(sa>n/2) while(sa>n/2){
			int t=qa.top().second;
			ans+=qa.top().first;
			qa.pop();
			sa--;
		}
		if(sb>n/2) while(sb>n/2){
			int t=qb.top().second;
			ans+=qb.top().first;
			qb.pop();
			sb--;
		}
		if(sc>n/2) while(sc>n/2){
			int t=qc.top().second;
			ans+=qc.top().first;
			qc.pop();
			sc--;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

