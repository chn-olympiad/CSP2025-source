#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,u,p,q;
struct f{
	int a1,a2,a3,maxn,maxi;
}a[100005];
bool cmp2(f o,f b){
	return o.a1>b.a1;
}
bool cmp3(f o,f b){
	return o.maxn>b.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		ans=0;
		int q1=0,q2=0,q3=0;
		cin>>n;
		u=1,p=0,q=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].a1=x;
			a[i].a2=y;
			a[i].a3=z;
			if(x>=y&&x>=z){
				a[i].maxn=x;
				a[i].maxi=1;
			}
			else if(y>=x&&y>=z){
				a[i].maxn=y;
				a[i].maxi=2;
			}
			else{
				a[i].maxn=z;
				a[i].maxi=3;
			}
		}
		while(n-q1-q2-q3){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n-q1-q2-q3;i++){
				if(a[i].maxi==1){
					if(q1==n/2){
						a[i].maxn=max(a[i].a3,a[1].a2);
						if(a[i].maxn==a[i].a2){
							a[i].maxi=2;
						}
						else{
							a[i].maxi=3;
						}
					}
					else{
						ans+=a[i].maxn;
						a[i].maxn=0;
						q1++;
					}
				}
				else if(a[i].maxi==2){
					if(q2==n/2){
						a[i].maxn=max(a[i].a1,a[1].a3);
						if(a[i].maxn==a[i].a1){
							a[i].maxi=1;
						}
						else{
							a[i].maxi=3;
						}
					}
					else{
						ans+=a[i].maxn;
						a[i].maxn=0;
						q2++;
					}
				}
				else{
					if(q3==n/2){
						a[i].maxn=max(a[i].a1,a[1].a2);
						if(a[i].maxn==a[i].a2){
							a[i].maxi=2;
						}
						else{
							a[i].maxi=1;
						}
					}
					else{
						ans+=a[i].maxn;
						a[i].maxn=0;
						q3++;
					}
				}
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
