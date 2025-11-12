#include<iostream>
#include<algorithm>
using namespace std;
int t,n,cnta,cntb,cntc;
long long ans,a[200010],b[200010],c[200010];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>=100000){
			for(int i=1;i<=n;i++){
				int y,z;cin>>a[i]>>y>>z;
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<"\n";
			ans=0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			int x,y,z;cin>>x>>y>>z;
			if(x>=y&&x>=z){
				ans+=x;
				a[++cnta]=min(x-y,x-z);
				//cout<<1<<' '<<x<<' '<<min(x-y,x-z)<<endl;
			}else{
				if(y>=x&&y>=z){
					ans+=y;
					b[++cntb]=min(y-x,y-z);
					//cout<<2<<' '<<y<<' '<<min(y-x,y-z)<<endl;
				}else{
					if(z>=x&&z>=y){
						ans+=z;
						c[++cntc]=min(z-x,z-y);
						//cout<<3<<' '<<z<<' '<<min(z-x,z-y)<<endl;
					}
				}
			}
		}
		if(cnta>n/2){
			sort(a+1,a+cnta+1,cmp);
			for(int i=cnta;i>n/2;i--)ans-=a[i];
		}
		if(cntb>n/2){
			sort(b+1,b+cntb+1,cmp);
			for(int i=cntb;i>n/2;i--)ans-=b[i];
		}
		if(cntc>n/2){
			sort(c+1,c+cntc+1,cmp);
			for(int i=cntc;i>n/2;i--)ans-=c[i];
		}
		cout<<ans<<"\n";//cout<<"\n\n";
		ans=cnta=cntb=cntc=0;
	}
}
