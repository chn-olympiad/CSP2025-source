#include<bits/stdc++.h>
using namespace std;
int t,n,am=-1,bm=-1,cm=-1;
struct sb{
	int a,b,c;
}k[1000001];
bool cmp(sb x,sb y){
	if(x.a>y.a) return 1;
	if(x.a<y.a) return 0;
	if(x.b>y.b) return 1;
	if(x.b<y.b) return 0;
	if(x.c>y.c) return 1;
	return 0;
}
bool cmq(sb x,sb y){
	if(x.c>y.c) return 1;
	return 0;
}
int Max(int x,int y){
	if(x>y) return x;
	return y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			k[i].a=0;
			k[i].b=0;
			k[i].c=0;
		}
		cin>>n;
		if(n==2){
			int a1,a2,a3,a4,a5,a6;
			cin>>a1>>a2>>a3>>a4>>a5>>a6;
			cout<<Max(Max((a1+Max(a5,a6)),(a2+Max(a4,a6))),(a3+Max(a4,a5)))<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			cin>>k[j].a>>k[j].b>>k[j].c;
			am=Max(am,k[j].a);
			bm=Max(bm,k[j].b);
			cm=Max(cm,k[j].c);
		}
		sort(k+1,k+n+1,cmp);
		if(bm==0&&cm==0){
			long long ans=0;
			for(int ii=1;ii<=n/2;ii++){
				ans+=k[ii].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if(cm==0){
			for(int ii=1;ii<=n;ii++){
				k[ii].c=k[ii].a-k[ii].b;
			}
			sort(k+1,k+n+1,cmq);
			long long ans=0;
			for(int ii=1;ii<=n;ii++){
				if(ii<=n/2) ans+=k[ii].a;
				else ans+=k[ii].b;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
} 
