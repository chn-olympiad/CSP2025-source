#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{
	int a,b,c;
}now;
int n,ans;
int a[maxn],b[maxn],c[maxn];
bool check(){
	if(now.a>n/2) return 1;
	else if(now.b>n/2) return 2;
	else if(now.c>n/2) return 3;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		now.a=0,now.b=0,now.c=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int maxx=max(a[i],max(b[i],c[i]));
			if(maxx==a[i]){
				ans+=a[i];
				now.a++;
			}
			else if(maxx==b[i]){
				ans+=b[i];
				now.b++;
			}
			else{
				ans+=c[i];
				now.c++;
			}
		}
		if(check()==0){
			cout<<ans<<endl;
			continue;
		}
		else{
			int aa=n/2-now.a,bb=n/2-now.b,cc=n/2-now.c;
			while(aa<0||bb<0||cc<0){
				if(aa<0){
					int minn=100000000,xb1,xb2;
					for(int i=1;i<=n;i++){
						if(minn>a[i]-b[i]&&a[i]-b[i]>0) xb1=i,xb2=1,minn=a[i]-b[i];
						if(minn>a[i]-c[i]&&a[i]-c[i]>0) xb1=i,xb2=2,minn=a[i]-c[i];
					}
					ans-=minn;
					aa++;
					if(xb2==1) bb--,swap(a[xb1],b[xb1]);
					else cc--,swap(a[xb1],c[xb1]);
				}
				if(bb<0){
					int minn=100000000,xb1,xb2;
					for(int i=1;i<=n;i++){
						if(minn>b[i]-a[i]&&b[i]-a[i]>0) xb1=i,xb2=1,minn=b[i]-a[i];
						if(minn>b[i]-c[i]&&b[i]-c[i]>0) xb1=i,xb2=2,minn=b[i]-c[i];
					}
					ans-=minn;
					bb++;
					if(xb2==1) aa--,swap(a[xb1],b[xb1]);
					else cc--,swap(b[xb1],c[xb1]);
				}
				if(cc<0){
					int minn=100000000,xb1,xb2;
					for(int i=1;i<=n;i++){
						if(minn>c[i]-b[i]&&c[i]-b[i]>0) xb1=i,xb2=1,minn=c[i]-b[i];
						if(minn>c[i]-a[i]&&c[i]-a[i]>0) xb1=i,xb2=2,minn=c[i]-a[i];
					}
					ans-=minn;
					cc++;
					if(xb2==2) bb--,swap(c[xb1],b[xb1]);
					else aa--,swap(a[xb1],c[xb1]);
				}
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
