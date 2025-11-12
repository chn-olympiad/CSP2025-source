#include<bits/stdc++.h>
using namespace std;
long long t,n,b1,c1,d1,x,ans,e[100010],p,f[100010];
string s;
struct node{
	long long d,b,c;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		b1=0,c1=0,d1=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b>>a[i].c>>a[i].d;
			x=max(a[i].b,max(a[i].c,a[i].d));
			if(x==a[i].b) b1++;
			if(x==a[i].c) c1++;
			if(x==a[i].d) d1++;
			ans+=x;
		}
			if(b1<=n/2&&c1<=n/2&&d1<=n/2){
				e[j]=ans;
			}
			else{
				ans=0;
				if(b1>n/2){
					p=b1-n/2;
					for(int i=1;i<=n;i++){
						f[i]=a[i].b-max(a[i].c,a[i].d);
					}
					sort(f+1,f+n+1);
					for(int i=1;i<=n;i++){
						for(int k=1;k<=p;k++){
							if(a[i].b-max(a[i].c,a[i].d)==f[k]) a[i].b=max(a[i].c,a[i].d);
						}
					}
					for(int i=1;i<=n;i++){
					x=max(a[i].b,max(a[i].c,a[i].d));
					ans+=x;
					}
					e[j]=ans;
				}
				if(c1>n/2){
					p=c1-n/2;
					for(int i=1;i<=n;i++){
						f[i]=a[i].c-max(a[i].b,a[i].d);
					}
					sort(f+1,f+n+1);
					for(int i=1;i<=n;i++){
						for(int k=1;k<=p;k++){
							if(a[i].c-max(a[i].b,a[i].d)==f[k]) a[i].c=max(a[i].b,a[i].d);
						}
					}
					for(int i=1;i<=n;i++){
					x=max(a[i].b,max(a[i].c,a[i].d));
					ans+=x;
					}
					e[j]=ans;
				}
				if(d1>n/2){
					p=d1-n/2;
					for(int i=1;i<=n;i++){
						f[i]=a[i].d-max(a[i].c,a[i].b);
					}
					sort(f+1,f+n+1);
					for(int i=1;i<=n;i++){
						for(int k=1;k<=p;k++){
							if(a[i].d-max(a[i].c,a[i].b)==f[k]) a[i].b=max(a[i].c,a[i].d);
						}
					}
					for(int i=1;i<=n;i++){
					x=max(a[i].b,max(a[i].c,a[i].d));
					ans+=x;
					}
					e[j]=ans;
				}
			}
		}	
	for(int i=1;i<=t;i++) cout<<e[i]<<endl;
	return 0;
} 
