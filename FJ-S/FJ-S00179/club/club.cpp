#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],b[5],c[100005],d[100005],e[100005],k,f[5],j;
int main(){
	cin>>t;
	while(t--){
		b[1]=0,b[2]=0,b[3]=0,f[1]=0,f[2]=0,f[3]=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			b[1]+=a[1][i],b[2]+=a[2][i],b[3]+=a[3][i]; 
		}
		for(int i=1;i<=n;++i){
			c[i]=min(a[1][i]-a[2][i],a[1][i]-a[3][i]); 
			d[i]=min(a[2][i]-a[1][i],a[2][i]-a[3][i]); 
			e[i]=min(a[3][i]-a[2][i],a[3][i]-a[1][i]); 
		}
		sort(c+1,c+1+n);
		sort(d+1,d+1+n);
		sort(e+1,e+1+n);
		for(int i=1;i<=n/2;++i){
			f[1]+=c[i];
			f[2]+=d[i];	
			f[3]+=e[i];
		}
		if(n>=200){
			j=1;
			while(c[n/2+j]<0){
				f[1]+=c[n/2+j];
				++j;
			}
			j=1;
			while(d[n/2+j]<0){
				f[2]+=d[n/2+j];
				++j;
			}
			j=1;
			while(e[n/2+j]<0){
				f[3]+=e[n/2+j];
				++j;
			}
		}
		k=max(b[1]-f[1],max(b[2]-f[2],b[3]-f[3]));
		cout<<k<<"\n";
		//cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<"\n"<<f[1]<<" "<<f[2]<<" "<<f[3]; 
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
