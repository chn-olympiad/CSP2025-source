#include<bits/stdc++.h>
using namespace std;
struct nd{
	int x,w,y;
}a1[100001],a2[100001],a3[100001];
long long n,x,y,z,ans,c1,c2,c3,t;
bool cmp(nd xx,nd yy){
	return xx.w>yy.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		c1=c2=c3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				a1[++c1].x=x,a1[c1].w=x;
				if(y>=z) a1[c1].y=y,a1[c1].w-=y;
				else  a1[c1].y=z,a1[c1].w-=z;
			}
			else if(y>=x&&y>=z){
				a2[++c2].x=y,a2[c2].w=y;
				if(x>=z) a2[c2].y=x,a2[c2].w-=x;
				else  a2[c2].y=z,a2[c2].w-=z;
			}
			else{
				a3[++c3].x=z,a3[c3].w=z;
				if(x>=y) a3[c3].y=x,a3[c3].w-=x;
				else  a3[c3].y=y,a3[c3].w-=y;
			}
		}
		sort(a1+1,a1+c1+1,cmp),sort(a2+1,a2+c2+1,cmp),sort(a3+1,a3+c3+1,cmp);
		for(int i=1;i<=c1;i++){
			if(i>n/2)ans+=a1[i].y;
			else ans+=a1[i].x;
		}
		for(int i=1;i<=c2;i++){
			if(i>n/2)ans+=a2[i].y;
			else ans+=a2[i].x;
		}
		for(int i=1;i<=c3;i++){
			if(i>n/2)ans+=a3[i].y;
			else ans+=a3[i].x;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
