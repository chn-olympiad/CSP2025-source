#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,n=0,a1=0,b1=0,c1=0,t=0,a=0,b=0,c=0,m=0,s=0,d=0,f=0,r=0,u=0,y=0,A[100005],B[100005],C[100005];
struct food{
	int nb=0;
	bool fg=0;
};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++)A[j]=0;
		for(int j=1;j<=n;j++)B[j]=0;
		for(int j=1;j<=n;j++)C[j]=0;
		ans=0;n=0;a=0;b=0;c=0;m=0;s=0;d=0;f=0;r=0;u=0;y=0;
		cin>>n;
		s=1;
		d=1;
		f=1;
		r=n/2;
		y=n/2;
		u=n/2;
		if(n==2){
			cin>>a>>b>>c;
			cin>>a1>>b1>>c1;
			ans=max(a+b1,a+c1);
			ans=max(ans,b+a1);
			ans=max(ans,b+c1);
			ans=max(ans,c+a1);
			ans=max(ans,c+b1);
			cout<<ans;
		}
		else{
			for(int j=1;j<=n;j++){
				cin>>a>>b>>c;
				m=max(a,b);
				m=max(m,c);
				if(m==a){
					A[s]=m;
					s++;
				}
				else if(m==b){
					B[d]=m;
					d++;
				}
				else if(m==c){
					C[f]=m;
					f++;
				}
			}
			sort(A+1,A+n+1);
			sort(B+1,B+n+1);
			sort(C+1,C+n+1);
			for(int k=n;k>=n/2;k--){
				ans+=A[k];
				r--;
				if(r==0)break;
			}
			for(int k=n;k>=n/2;k--){
				ans+=B[k];
				y--;
				if(y==0)break;
			}
			for(int k=n;k>=n/2;k--){
				ans+=C[k];
				u--;
				if(u==0)break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}