#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int s[5],p[5];
}a[N];
struct temp{
	int s,y;
}e[5];
bool cmp(temp x,temp y){
	return x.s>y.s;
}
bool cmmp(node x,node y){
	if(x.s[1]-x.s[2]!=y.s[1]-y.s[2]) return x.s[1]-x.s[2]>y.s[1]-y.s[2];
	return x.s[2]-x.s[3]>y.s[2]-y.s[3];
}
int jl[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[1].s,&e[2].s,&e[3].s);
			e[1].y=1,e[2].y=2,e[3].y=3;
			sort(e+1,e+1+3,cmp);
			for(int j=1;j<=3;j++) a[i].s[j]=e[j].s,a[i].p[j]=e[j].y;
		}
		sort(a+1,a+1+n,cmmp);
		for(int i=1;i<=n;i++){
			if(jl[a[i].p[1]]<n/2) jl[a[i].p[1]]++,ans+=a[i].s[1];
			else if(jl[a[i].p[2]]<n/2) jl[a[i].p[2]]++,ans+=a[i].s[2];
			else jl[a[i].p[3]]++,ans+=a[i].s[3];
		}
		cout<<ans<<"\n";
		memset(jl,0,sizeof(jl));
	}
	return 0;
}
