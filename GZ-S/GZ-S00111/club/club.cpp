//GZ-S00111 贵阳市第一中学  周熙原 
#include<bits/stdc++.h>
using namespace std;
struct tot{
	int z;
	int i;
} ;
bool cmp(tot a,tot b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		tot d[100005];
	tot e[100005];
	int a[100005],b[100005],c[100005],vis[100005]={};
		for(int i=0;i<=100004;i++) vis[i]=0;
	int n,ca=0,cb=0,cc=0;
		long long s=0;
	cin>>n;
		for(int j=1;j<=n;j++){
				cin>>a[j]>>b[j]>>c[j];
		d[j].z=min(a[j]-b[j],a[j]-c[j]);
		e[j].z=b[j]-c[j];
	d[j].i=j;
		e[j].i=j;
		}
	sort(d+1,d+n+1,cmp);
		sort(e+1,e+n+1,cmp);
		for(int j=n;j>=1;j--,ca++){
			if(d[j].z<0||j<n/2) cout<<1;
			{
				break;
			}
		 vis[d[j].i]=1,s+=a[d[j].i];
		}
		for(int j=n,c=0;j>=1;j--,cb++)
		{
			if(e[j].z<0||c>n/2){
				break;
			}
			if(vis[e[j].i]==0)
		 vis[e[j].i]=1,s+=b[e[j].i],c++;
		}
		for(int j=1,ca=0;j<=n;j++,cc++){
			if(ca>n/2||e[j].z>=0){
				break;
			}
			if(vis[e[j].i]==0){
		 vis[e[j].i]=1;
		 s+=c[e[j].i];
		 ca++;}
		}
		for(int i=1;i<=n;i++){
					if(vis[i]==0){
				if(max(a[i],max(b[i],c[i]))==a[i]){
					if(ca<n/2) s+=a[i],ca++;
					else {
					if(b[i]>c[i]){
						s+=b[i],cb++;
					}
					else s+=c[i],cc++;
					}
				}
				if(max(a[i],max(b[i],c[i]))==b[i]){
					if(cb<n/2) s+=b[i],cb++;
					else {
					if(a[i]>c[i]){
						s+=a[i],ca++;
				}
					else s+=c[i],cc++;
					}			}
				if(max(a[i],max(b[i],c[i]))==c[i]){
				if(cc<n/2) s+=c[i],cc++;
					else {
					if(a[i]>b[i]){
						s+=a[i],ca++;
					}
					else s+=b[i],cb++;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
