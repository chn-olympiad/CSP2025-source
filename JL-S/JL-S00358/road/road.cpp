#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[10001],x[1000001],y[1000001],z[1000001],q[1000001],p,f=0,ans=0; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		c[i]=i+1;
		cin>>x[i]>>y[i]>>z[i];
		q[i]=z[i];
		z[i]=z[i]*10+i;
	}
	sort(z,z+m);
	sort(q,q+m);
	for(int i=0;i<m;i++){
		f=0;
		p=z[i]%10;
		ans+=q[i];
		for(int j=0;j<n;j++){
			if(c[j]==x[p]||c[j]==y[p]){
				c[j]=0;
			}
		}
		for(int j=0;j<m;j++){
			if(c[j]!=0) f=1;
		}
		if(!f) break;
	}
	cout<<ans<<endl;
	return 0;

}
