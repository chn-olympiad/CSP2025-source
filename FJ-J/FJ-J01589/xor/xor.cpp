#include <bits/stdc++.h>
#define ifo(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],g[maxn],ans;
bool v[maxn];
struct t{
	int p,q;
	t(){p=0,q=0;}
	bool operator<(const t other)const{
		return q-p>(other.q-other.p);
	}
};
priority_queue<t>pq;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	g[0]=0;
	ifo(i,1,n)cin>>a[i],g[i]=g[i-1]^a[i];
	ifo(i,1,n)ifo(j,i,n)
		if(g[j]^g[i-1]==k)
		{
			t t1;
			t1.p=i,t1.q=j;
			pq.push(t1);
		}
		while(!pq.empty()){
			int p1=pq.top().p,q1=pq.top().q;
			pq.pop();
			bool v1=1;
			ifo(i,p1,q1)if(v[i])v1=0;
			if(v1==1){
				ifo(i,p1,q1)v[i]=1,ans++;
			}
		}
	cout<<ans/2; 
	return 0;
}
 
