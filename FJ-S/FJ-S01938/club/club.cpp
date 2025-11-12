#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6;

int rd() {
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=x*10+ch-'0';
		ch=getchar();
	} 
	return x*f; 
}

int t,n,a[N],b[N],c[N]; 
int f[N],ans,tmp[N],cnt=0;
int b1,b2,b3;
bool cmp (int x,int y) {
	return x>y;
} 
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd();
	
	while(t--) {
		ans=0;
		n=rd();
		for(int i=1;i<=n;i++) {
			a[i]=rd();b[i]=rd(); c[i]=rd(); 
		}
		b1=b2=b3=0;
		for(int i=1;i<=n;i++) {
			if(a[i]>=b[i]&&a[i]>=c[i]) {
				f[i]=1; b1++; ans+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]) {
				f[i]=2; b2++; ans+=b[i];
			}
			else {
				f[i]=3; b3++; ans+=c[i];
			}
		} 
		if(b1<=n/2&&b2<=n/2&&b3<=n/2) {
			cout<<ans<<'\n';
			
		}
		else {
			cnt=0;
			if(b1*2>=n) {
				for(int i=1;i<=n;i++) {
					if(f[i]==1) {
						tmp[++cnt]=max(b[i],c[i])-a[i];
					}
				}
				sort(tmp+1,tmp+1+cnt,cmp);          
				for(int i=1;i<=b1-n/2;i++) {
					ans+=tmp[i];
				} 
				///cout<<1<<' ';
			}
			if(b2*2>=n) {
		///		cout<<b2<<' '<<n<<' '<<n/2-b2<<'\n';
				for(int i=1;i<=n;i++) {
					if(f[i]==2) {
						tmp[++cnt]=max(a[i],c[i])-b[i];
					}
				}
				sort(tmp+1,tmp+1+cnt,cmp); 
			//	cout<<"s"<<'\n';         
				for(int i=1;i<=b2-n/2;i++) {
				//	cout<<tmp[i]<<' ';
					ans+=tmp[i];
				} 
			//	cout<<"e\n";
			//	cout<<2<<' ';
			}
		//	for(int i=1;i<=cnt;i++) cout<<tmp[i]<<' ';
		//	cout<<'\n';
			if(b3*2>=n) {
				for(int i=1;i<=n;i++) {
					if(f[i]==3) {
						tmp[++cnt]=max(a[i],b[i])-c[i];
					}
				}
				sort(tmp+1,tmp+1+cnt,cmp);          
				for(int i=1;i<=b3-n/2;i++) {
					ans+=tmp[i];
				} 
			//	cout<<3<<' ';
			}
			cout<<ans<<'\n';
		}
	} 
	return 0;
} 
