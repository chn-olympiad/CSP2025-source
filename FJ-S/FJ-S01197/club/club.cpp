#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int p[5];
int b[100005][5];
int sum=0;
int l=0;
int x=0;
struct xxx{
	int frog=0;
	int maxn=0;
	int minn=0;
	int midn=0;
	int m1,m2,m3;
}a[100005];
bool first(xxx x,xxx y){
	if(x.maxn!=y.maxn) return x.maxn>y.maxn;
	return x.midn<y.midn;
}
bool second(xxx x,xxx y){
	if(x.midn!=y.midn) return x.midn>y.midn;
	return x.minn<y.minn;
}
bool third(xxx x,xxx y){
	return x.minn>y.minn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,1,n);
		memset(b,1,n);
		memset(p,1,5);
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int j=1;
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			if(b[i][2]!=0||b[i][3]!=0) l=1;
			a[i].maxn=max(b[i][1],max(b[i][2],b[i][3]));
			a[i].minn=min(b[i][1],min(b[i][2],b[i][3]));
			a[i].midn=b[i][1]+b[i][2]+b[i][3]-a[i].maxn-a[i].minn;
			while(j<=3){
				if(b[i][j]==a[i].maxn) a[i].m1=j;
				else if(b[i][j]==a[i].midn) a[i].m2=j;
				else a[i].m3=j;
				j++;								
			}	
		}	
		sort(a+1,a+1+n,first);
		for(int i=1;i<=n;i++){
			if(p[a[i].m1]<=n/2){
				p[a[i].m1]++;
				a[i].frog=1;
				sum+=a[i].maxn;
			}
		}
		if(l==0){
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+1+n,second);
		for(int i=1;i<=n;i++){
			if(p[a[i].m2]<=n/2&&a[i].frog==0){
				p[a[i].m2]++;
				a[i].frog=1;
				sum+=a[i].midn;
			}
		}
		sort(a+1,a+1+n,third);
		for(int i=1;i<=n;i++){
			if(a[i].frog==0)
				sum+=a[i].minn;
		}
	
		cout<<sum<<endl;	
	}
	
	return 0;
}
