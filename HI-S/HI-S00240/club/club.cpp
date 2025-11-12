#include <bits/stdc++.h>
using namespace std;
int r=-1,rr=-1;
long long int e,f,q;
long long int zz=0,n,a[100005],b[100005],c[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	a[0]=-1;
	b[0]=-1;
	c[0]=-1;
	int t;
	cin>>t;
	for(int qwq=1;qwq<=t;qwq++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				r=1;
			}
		}
		if(r==-1){
			sort(a+1,a+n+1);
			zz=0;
			for(int j=1;j<=n/2;j++){
				zz+=a[n-j+1];
			}
		}else{
			if(n==2){
				q=max(a[1]+b[2],a[1]+c[2]);
				q=max(q,b[1]+a[2]);
				q=max(q,b[1]+c[2]);
				q=max(q,c[1]+b[2]);
				q=max(q,c[1]+a[2]);
				zz=q;
			}else{
				zz=0;
				e=0;
				for(int g=1;g<=n/2;g++){
					for(int y=1;y<=n;y++){
						if(a[y]>a[e]){
							e=y;
						}
					}
					zz+=a[e];
					a[e]=-1;
					b[e]=-1;
					c[e]=-1;
					e=0;
				}
				for(int g=1;g<=n/2;g++){
					for(int y=1;y<=n;y++){
						if(b[y]>b[e]){
							e=y;
						}
					}
					zz+=b[e];
					a[e]=-1;
					b[e]=-1;
					c[e]=-1;
					e=0;
				}
			}
		}
		cout<<zz<<endl;
	}
	return 0;
} 
