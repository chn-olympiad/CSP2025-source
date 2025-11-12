#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010],b[100010],c[100010],x,z,l;
int s1[100100],s2[100100],s3[100100],o;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
    	x=z=l=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
		    cin>>a[i]>>b[i]>>c[i];
		    int d=max(a[i],b[i]);
		    int e=max(b[i],c[i]);
		   	if(b[i]>a[i]&&b[i]>c[i]){
		    	z++;
		 	  	s2[z]=d-max(a[i],c[i]);
		  	  	ans+=b[i];
			}
		    else{
			    if(d>e){
				    x++;
				    s1[x]=d-e;
				    ans+=a[i];
				}
			    else{
				    l++;
				    s3[l]=e-d;
				    ans+=c[i];
				}
			}
		    
		}
		if(x>n/2){
			sort(s1+1,s1+1+x);
			for(int i=1;i<=x-n/2;i++) ans-=s1[i];
		}
		if(z>n/2){
			sort(s2+1,s2+1+z);
			for(int i=1;i<=z-n/2;i++) ans-=s2[i];
		}
		if(l>n/2){
			sort(s3+1,s3+1+l);
			for(int i=1;i<=l-n/2;i++) ans-=s3[i]; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
