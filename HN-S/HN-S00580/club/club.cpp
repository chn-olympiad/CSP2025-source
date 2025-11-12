#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e5+100;
int t,n,sum,c1,c2,c3,tzi;
struct jgt{
	int tz,xz;
}e[N];
bool cmp(jgt a,jgt b){
	if(a.xz==tzi){
		if(b.xz!=tzi) return 1;
		return a.tz<b.tz;
	}
	if(b.xz==tzi){
		return 0;
	}
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=c1=c2=c3=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=max(y,z)){
				c1++;
				sum+=x;
				e[i].xz=1;
				e[i].tz=min(x-y,x-z);
			}else if(y>=max(x,z)){
				c2++;
				sum+=y;
				e[i].xz=2;
				e[i].tz=min(y-x,y-z);
			}else{
				c3++;
				sum+=z;
				e[i].xz=3;
				e[i].tz=min(z-x,z-y);
			}
		}
		if(c1>n/2||c2>n/2||c3>n/2){
			int cha;
			if(c1>n/2) tzi=1,cha=c1-n/2;
			else if(c2>n/2) tzi=2,cha=c2-n/2;
			else tzi=3,cha=c3-n/2;
			sort(e+1,e+n+1,cmp);
			for(int i=1;i<=cha;i++) sum-=e[i].tz;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
