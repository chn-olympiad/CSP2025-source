#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	int f[t+1];
	for(int q=1;q<=t;q++){
		cin>>n;
		int a[n+1],b[n+1],c[n+1];
		int a1=0,b1=0,c1=0;
		int a2=0,b2=0,c2=0;
		int a3[n+1],b3[n+1],c3[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			a3[i]=a[i];
			b3[i]=b[i];
			c3[i]=c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				a1++;
				continue;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				b1++;
				continue;
			}else if(c[i]>=b[i]&&c[i]>=a[i]){
				c1++;
				continue;
			}
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		bool s;
		if(a1>=b1&&b1>=c1){
			for(int j=n;a2<n/2+1;j--){
				s=true;
				for(int k=1;k<=n;k++){
					if(a3[k]==a[j]||b3[k]==a[j]||c3[k]==a[j]){
						if(a3[k]==-1||b3[k]==-1||c3[k]==-1){
						s=false;
					}
					}
				}if(s==true){
					f[q]+=a[j];
				a2++;
				a[j]=-1;
				}
			}
			
		}else if(b1>=c1&&b1>=a1){
			for(int j=n;b2<n/2+1;j--){
				s=true;
				for(int k=1;k<=n;k++){
					if(a3[k]==b[j]||b3[k]==b[j]||c3[k]==b[j]){
						if(a3[k]==-1||b3[k]==-1||c3[k]==-1){
						s=false;
					}
					}
				}if(s==true){
					f[q]+=b[j];
				b2++;
				b[j]=-1;
				}
			}
		}else if(c1>=c1&&c1>=a1){
			for(int j=n;c2<n/2+1;j--){
				s=true;
				for(int k=1;k<=n;k++){
					if(a3[k]==c[j]||b3[k]==c[j]||c3[k]==c[j]){
						if(a3[k]==-1||b3[k]==-1||c3[k]==-1){
						s=false;
					}
					}
				}if(s==true){
					f[q]+=c[j];
				c2++;
				c[j]=-1;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<f[i]<<endl;
	}

	return 0;
}
