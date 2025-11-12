#include<bits/stdc++.h>
using namespace std;
int t;
long long n,maxn;
struct node{
	long long a,b,c;
}u[100050];
long long z[100050];
int cmp(node x,node y){
	return x.a>y.a;
}
void dfs(long long x_,long long val,long long d_1,long long d_2,long long d_3){
	if(x_==n+1){
		maxn=max(maxn,val);
		return ;
	}
	if(d_1<n/2) dfs(x_+1,val+u[x_].a,d_1+1,d_2,d_3);
	if(d_2<n/2) dfs(x_+1,val+u[x_].b,d_1,d_2+1,d_3);
	if(d_3<n/2) dfs(x_+1,val+u[x_].c,d_1,d_2,d_3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int A=1,B=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>u[i].a>>u[i].b>>u[i].c;
			if(u[i].b!=0) A=0;
			if(u[i].c!=0) A=0,B=0;
		}
		if(A){
			long long sum=0;
			sort(u+1,u+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=u[i].a; 
			}
			cout<<sum<<endl;
			continue;
		}
		if(B){
			long long aa=0,bb=0,ans=0;
			for(int i=1;i<=n;i++){
				z[i]=u[i].a-u[i].b;
				if(u[i].a>=u[i].b){
					aa++;
					ans+=u[i].a;
				}
				else{
					bb++;
					ans+=u[i].b;
				}
			}
			if(aa<=n/2&&bb<=n/2) cout<<ans<<endl;
			else{
				if(aa>n/2){
					int st_1=aa-(n/2);
					sort(z+1,z+n+1);
					for(int i=1;i<=n;i++){
						if(!st_1) break;
						if(z[i]<0) continue;
						st_1--;
						ans-=z[i];
					}
					cout<<ans<<endl;
				}
				else{
					int st_2=bb-(n/2);
					sort(z+1,z+n+1);
					for(int i=n;i>=1;i--){
						if(!st_2) break;
						if(z[i]>0) continue;
						st_2--;
						ans+=z[i];
					}
					cout<<ans<<endl;
				}
			}
			continue;
		}
		if(n<=10){
			maxn=-1;
			dfs(1,0,0,0,0);
			cout<<maxn<<endl;
			continue;
		}
	}
	return 0;
}
