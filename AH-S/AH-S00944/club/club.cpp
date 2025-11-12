#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
struct node{
	long long a,b,c,maxn;
}x[N];
struct ggg{
	long long s,id;
}a[N],b[N],c[N];
long long maxn[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n,s1=0,s2=0,s3=0,k1=0,k2=0,k3=0,g=0,h=0;
		bool f=0,flag=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].c!=0) f=1;
		}
		if(f==0){
			long long ans=0,kt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j) maxn[++ans]=x[i].a+x[j].b;
				}
			}
			sort(maxn+1,maxn+ans+1);
			long long p=n/2;
			while(p--){
				kt+=maxn[ans--];
			}
			cout<<kt<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(x[i].a>x[i].b&&x[i].a>x[i].c){
					a[++k1].s=x[i].a;
					a[k1].id=i;
				}
			}
			for(int i=1;i<=k1;i++){
				for(int j=i;j<=k1;j++){
					if(a[i].s<a[j].s) swap(a[i],a[j]);
				}
			}
			for(int i=1;i<=n/2;i++){
				x[a[i].id].a=0;
				x[a[i].id].b=0;
				x[a[i].id].c=0;
				s1+=a[i].s;
			}
			for(int i=n/2+1;i<=n;i++) x[a[i].id].a=0;
			for(int i=1;i<=n;i++){
				if(x[i].b>x[i].a&&x[i].b>x[i].c){
					b[++k2].s=x[i].b;
					b[k2].id=i;
				}
			}
			for(int i=1;i<=k2;i++){
				for(int j=i;j<=k2;j++){
					if(b[i].s<b[j].s) swap(b[i],b[j]);
				}
			}
			for(int i=1;i<=n/2;i++){
				x[b[i].id].a=0;
				x[b[i].id].b=0;
				x[b[i].id].c=0;
				s2+=b[i].s;
			}
			for(int i=n/2+1;i<=n;i++) x[b[i].id].b=0;
			for(int i=1;i<=n;i++){
				if(x[i].c>x[i].a&&x[i].c>x[i].b){
					c[++k3].s=x[i].c;
					c[k3].id=i;
				}
			}
			for(int i=1;i<=k3;i++){
				for(int j=i;j<=k3;j++){
					if(c[i].s<c[j].s) swap(c[i],c[j]);
				}
			}
			for(int i=1;i<=n/2;i++){
				x[c[i].id].a=0;
				x[c[i].id].b=0;
				x[c[i].id].c=0;
				s3+=c[i].s;
			}
			for(int i=n/2+1;i<=n;i++) x[c[i].id].c=0;
			cout<<s1+s2+s3<<endl;
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	return 0;
}
