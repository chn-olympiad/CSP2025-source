#include<bits/stdc++.h>
using namespace std;
#define N 100005

struct mem{
	int num,v;
};

bool cmp(mem xx,mem yy){
	return xx.v>yy.v;
}

int t;
int n,a[N][4];
mem x[N],y[N],z[N];
int c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long an=0;
		cin>>n;
		//memset(a,0,(n+2)*sizeof(int));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x[i].num=i, x[i].v=a[i][1];
			y[i].num=i, y[i].v=a[i][2];
			z[i].num=i, z[i].v=a[i][3];
		}
		long long ans=0;
		{	
		sort(x+1,x+1+n,cmp);
		sort(y+1,y+1+n,cmp);
		sort(z+1,z+1+n,cmp);
		
		for(int i=1;i<=n/2;i++){
			ans+=x[i].v;
			c[i]=1;
		}
		int cnt=n/2;
		int re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=y[i].num;
			if(c[tn]==1){
				if(a[tn][1]>=a[tn][2]){
					re++;
					continue;
				}
				else{
					cnt--;
					ans=ans-a[tn][1]+a[tn][2];
					c[tn]=2;
				}
			}
			else if(c[tn]==2){
				if(a[tn][2]>=a[tn][3]){
					re++;
					continue;
				}
				else{
					cnt--;
					re++;
					ans=ans-a[tn][2]+a[tn][3];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][2];
				c[tn]=2;
			}
		}
		cnt+=n/2;
		re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=z[i].num;
			if(c[tn]==1){
				if(a[tn][1]>=a[tn][3]){
					re++;
					continue;
				}
				else{
					cnt--;
					re++;
					ans=ans-a[tn][1]+a[tn][3];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][3];
				c[tn]=3;
			}
		}
		}
		an=max(an,ans);
		/*ans=0;
		{	
		for(int i=1;i<=n/2;i++){
			ans+=y[i].v;
			c[i]=1;
		}
		int cnt=n/2;
		int re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=z[i].num;
			if(c[tn]==1){
				if(a[tn][2]>=a[tn][3]){
					re++;
					continue;
				}
				else{
					cnt--;
					ans=ans-a[tn][2]+a[tn][3];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][3];
				c[tn]=2;
			}
		}
		cnt+=n/2;
		re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=x[i].num;
			if(c[tn]==1){
				if(a[tn][2]>=a[tn][1]){
					re++;
					continue;
				}
				else{
					cnt--;
					re++;
					ans=ans-a[tn][2]+a[tn][1];
					c[tn]=2;
				}
			}
			else if(c[tn]==2){
				if(a[tn][3]>=a[tn][1]){
					re++;
					continue;
				}
				else{
					cnt--;
					re++;
					ans=ans-a[tn][3]+a[tn][1];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][1];
				c[tn]=3;
			}
		}
		}
		an=max(an,ans);
		ans=0;
		{
		for(int i=1;i<=n/2;i++){
			ans+=z[i].v;
			c[i]=1;
		}
		int cnt=n/2;
		int re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=x[i].num;
			if(c[tn]==1){
				if(a[tn][3]>=a[tn][1]){
					re++;
					continue;
				}
				else{
					cnt--;
					ans=ans-a[tn][3]+a[tn][1];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][1];
				c[tn]=2;
			}
		}
		cnt+=n/2;
		re=n-cnt;
		for(int i=1;i<=re;i++){
			int tn=y[i].num;
			if(c[tn]==1){
				if(a[tn][3]>=a[tn][2]){
					re++;
					continue;
				}
				else{
					cnt--;
					re++;
					ans=ans-a[tn][3]+a[tn][2];
					c[tn]=2;
				}
			}
			else{
				ans+=a[tn][2];
				c[tn]=3;
			}
		}
		}
		an=max(an,ans);*/
		
		
		
		cout<<an<<endl;
		
		
		
	}
	
	return 0;
}
