#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,res1,res2,res3,ans;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res1=res2=res3=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>y&&x>z){
				ans+=x;
				a[++res1]=min(x-y,x-z);
			}else if(y>x&&y>z){
				ans+=y;
				b[++res2]=min(y-x,y-z);
			}else if(z>x&&z>y){
				ans+=z;
				c[++res3]=min(z-x,z-y);
			}else if(x==y||x==z){
				ans+=x;
				a[++res1]=0;
			}else if(y==z){
				ans+=y;
				b[++res2]=0;
			}
		}
		if(res1>n/2){
			sort(a+1,a+1+res1);
			for(int i=1;i<=res1-n/2;i++){
				ans-=a[i];
			}
		}else if(res2>n/2){
			sort(b+1,b+1+res2);
			for(int i=1;i<=res2-n/2;i++){
				ans-=b[i];
			}
		}else if(res3>n/2){
			sort(c+1,c+1+res3);
			for(int i=1;i<=res3-n/2;i++){
				ans-=c[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
