#include<bits/stdc++.h>
using namespace std;

long long t,n,ans;

struct ren{
	long long a,b,c;
}r[100005];

void cz(long long x,long long y,long long e,long long s,long long sum){
	if(y>n/2 || e>n/2 || s>n/2)
		return;	
//	cout<<x<<" "<<y<<" "<<e<<' '<<s<<' '<<sum<<"\n";	
	ans=max(ans,sum);
	if(x>n)		
		return;
	if(r[x].a)
		cz(x+1,y+1,e,s,sum+r[x].a);
	if(r[x].b)
		cz(x+1,y,e+1,s,sum+r[x].b);
	if(r[x].c)
		cz(x+1,y,e,s+1,sum+r[x].c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(r,0,sizeof(r));
		for(int i=1;i<=n;i++)
			cin>>r[i].a>>r[i].b>>r[i].c;
		cz(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
