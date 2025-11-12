#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,c,maxx,minx;
}a[100005];
bool cmp(node a,node b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0,cnt=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1,u,v,w;i<=n;i++){
			cin>>u>>v>>w;
			if(u==v&&v==w){
				ans+=u;
				continue;
			}
			if(u==v&&u>w){
				ans+=u;
				continue;
			}
			if(u==w&&u>v){
				ans+=u;
				continue;
			}
			if(v==w&&v>u){
				ans+=v;
				continue;
			}
			else{
				cnt++,a[cnt].x=u,a[cnt].y=v,a[cnt].z=w;
				a[cnt].maxx=max(a[cnt].x,max(a[cnt].y,a[cnt].z)),a[i].minx=min(a[cnt].x,min(a[cnt].y,a[cnt].z));
				a[cnt].c=2*a[cnt].maxx+a[cnt].minx-(a[cnt].x+a[cnt].y+a[cnt].z);
			}
		}
		sort(a+1,a+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			if(a[i].x==a[i].maxx){
				if(cnt1>=n/2) ans+=(a[i].x-a[i].c),cnt2++;
				else ans+=a[i].x,cnt1++;
			}
			if(a[i].y==a[i].maxx){
				if(cnt2>=n/2) ans+=(a[i].y-a[i].c),cnt3++;
				else ans+=a[i].y,cnt2++;
			}
			if(a[i].z==a[i].maxx){
				if(cnt3>=n/2) ans+=(a[i].z-a[i].c),cnt1++;
				else ans+=a[i].z,cnt3++;
			}
		}
		cout<<ans<<endl;
	}
}
