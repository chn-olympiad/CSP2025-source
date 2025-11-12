#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,a[N][4],s[N][4],sum[N];

int s_max(int a,int b,int c){
	if(a>=b&&a>=c)return 1;
	else if(b>=a&&b>=c)return 2;
	else if(c>=a&&c>=b)return 3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		int q=0,p;
		int u[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			s[i][1]=s[i][2]=s[i][3]=0;
			int o=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=o;
			int o1=s_max(a[i][1],a[i][2],a[i][3]);
			s[i][o1]++;
			u[o1]++;
			if(u[o1]>m){
				q=o1;
				p=u[o1]-m;
			}
		}
		if(!q){
			cout<<ans<<endl;
			continue;
		}
		//cout<<q<<" "<<p<<endl;
		int e,el;
		if(q==1){
			e=2,el=3;
		}else if(q==2){
			e=1,el=3;
		}else{
			e=1,el=2;
		}
		int f=0;
		for(int i=1;i<=n;i++){
			if(s[i][q]){
				f++;
				sum[f]=min(a[i][q]-a[i][e],a[i][q]-a[i][el]);
			}
		}
		sort(sum+1,sum+1+f);
		for(int i=1;i<=p;i++)ans-=sum[i];
		cout<<ans<<endl;
	}
	return 0;
}
