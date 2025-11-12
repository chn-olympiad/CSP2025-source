#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
struct stu{
	ll id;
	ll z;
};
ll t,n; 
stu a[N],b[N],c[N];
bool vis[N];
bool cmp(stu x,stu y){
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(ll i=1;i<=n;i++){
			cin>>a[i].z>>b[i].z>>c[i].z;
			a[i].id=b[i].id=c[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		ll sum=0,flag=1;
		if(b[1].z==0 && c[1].z==0){
			for(int i=1;i<=n/2;i++){
				sum+=a[i].z;
			}
			cout<<sum<<endl;
			flag=0;
		}
		ll na=1,nb=1,nc=1,ca=0,cb=0,cc=0,cnt=0,lit=n/2;
		while(cnt<n && flag){
			while(vis[a[na].id]==1 && na<=n){
				na++;
			}
			while(vis[b[nb].id]==1 && nb<=n){
				nb++;
			}
			while(vis[c[nc].id]==1 && nb<=n){
				nc++;
			}
			if(a[na].z>=b[nb].z && na<=n && nb<=n){
				if(a[na].z>=c[nc].z && ca<lit){
					sum+=a[na].z;
					cnt++;
					ca++;
//					cout<<a[na].z<<endl;
					vis[a[na].id]=1;
					na++;
				}
				else if(cc<lit){
					sum+=c[nc].z;
					cnt++;
					cc++;
//					cout<<c[nc].z<<endl;
					vis[c[nc].id]=1;
					nc++;
				}
			}
			else if(nb<=n && nc<=n){
				if(b[nb].z>=c[nc].z && cb<lit){
					sum+=b[nb].z;
					cnt++;
					cb++;
//					cout<<b[nb].z<<endl;
					vis[b[nb].id]=1;
					nb++;
				}
				else if(cc<lit){
					sum+=c[nc].z;
					cnt++;
					cc++;
//					cout<<c[nc].z<<endl;
					vis[c[nc].id]=1;
					nc++;
				}
			}
		}
		if(flag){
			cout<<sum<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

