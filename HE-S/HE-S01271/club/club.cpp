#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
struct myd {
	int bh;
	int a,b,c;
	bool vis;
}e[N];
bool cmpa(myd x,myd y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		long long ans=0;
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			e[i].bh=i;
			e[i].vis=false;
		}
		sort(e+1,e+n+1,cmpa);
		for(int i=1;i<=n/2;i++){
		 	ans+=e[i].a;
		}
		cout<<ans;
	}
	return 0;
}
