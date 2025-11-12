#include<bits/stdc++.h>
using namespace std;
int n,t,ans,ans1,ans2,ans3,al,bl,cl,x=0,y=0,z=0,o,o1,o2;
long long a[100005],b[100005],c[100005],xx[100005],yy[100005],zz[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	ans1=0;
	ans2=0;
	ans3=0;
	while(t--){
		for(int i=1;i<=n;i++){
			xx[i]=-1;
			yy[i]=-1;
			zz[i]=-1;
		}
		x=0;
		y=0;
		z=0;
		ans=0;
		cin>>n;
		int shu=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i]; 
		}
		while(n--) {
			x=0;
			y=0;
			z=0;
			o=0,o1=0,o2=0;
			al=0;
			bl=0;
			cl=0;
			for(int i=1;i<=n-1;i++){
				if(a[i]>a[i+1]&&i!=x){
					for(int j=1;j<=n;j++){
						if(xx[j]==i){
							o=1;
						}
					}
					if(ans1<a[i]&&o!=1){
						ans1=a[i];
						x=i;
					}
				}
			}
			if(al<shu){
				ans=ans+ans1;	
				al++;
				xx[x]=x;
			}
			for(int i=1;i<=n-1;i++){
				if(b[i]>b[i+1]&&i!=y){
					for(int j=1;j<=n;j++){
						if(yy[j]==i){
							o1=1;
						}
					}
					if(ans2<b[i]&&o1!=1){
						ans2=b[i];
						y=i;
					}
				}
			}
			if(bl<shu){
				ans=ans+ans2;
				bl++;
				yy[y]=y;
			}
			for(int i=1;i<=n-1;i++){
				if(c[i]>c[i+1]&&i!=z){
					for(int j=1;j<=n;j++){
						if(zz[j]==i){
							o2=1;
						}
					}
					if(ans3<c[i]&&o2!=1){
						ans3=c[i];
						z=i;
					}
				}
			}
			if(cl<shu){
				ans=ans+ans3;
				cl++;
			}
			zz[z]=z;
		}
	cout<<ans<<endl;
	}
	return 0;
} 
