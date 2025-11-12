#include<bits/stdc++.h>
using namespace std;
long long n,a[20],b[20],c[20],t,k[10],kk[10],kkk[10],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long f[10010]={0},y[10010],cn;
		cin>>n;
		cn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			k[i]=a[i],kk[i]=b[i],kkk[i]=c[i];
		}
		sort(k+1,k+1+n);
		sort(kk+1,kk+1+n);
		sort(kkk+1,kkk+1+n);
		if(kk[n]==0&&kkk[n]==0){
			for(int i=n;i>cn;i--){
				ans+=k[i];
			}
			cout<<ans;
			break;
		}
		long long l=0,w=0,q=0;
		for(int i=1;i<=n;i++){
			y[i]=f[i];
			if(l<cn){
				y[i]=max(y[i],y[i-1]+a[i]);
			}
			if(w<cn){
				y[i]=max(y[i],y[i-1]+b[i]);
			}
			if(q<cn){
				y[i]=max(y[i],y[i-1]+b[i]);
			}
			if(y[i]==f[i-1]+a[i]){
				l++;
			}
			if(y[i]==f[i-1]+b[i]){
				w++;
			}
			if(y[i]==f[i-1]+c[i]){
				q++;
			}
		}
		cout<<y[n]<<endl;
	}
	return 0;
}
