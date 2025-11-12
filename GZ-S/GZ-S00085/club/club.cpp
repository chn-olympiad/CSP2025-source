//GZ-S00085 遵义市汇川区第三小学 吴昊然 
#include <bits/stdc++.h>
using namespace std;
struct aa{
	long long x,y,z,mi,mx;
};
bool cmp(aa l,aa r){
	if(l.mi!=r.mi)return l.mi<r.mi;
	return l.mx<r.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		aa a[n];
		long long f[4]={};
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y){
				a[i].mi=1;
				a[i].mx=a[i].x;
			} else{
				a[i].mi=2;
				a[i].mx=a[i].y;
			}
			if(a[i].mx<a[i].z){
				a[i].mi=3;
				a[i].mx=a[i].z;
			}
			f[a[i].mi]++;
		}
		if(f[1]>n/2){
			long long p=f[1]-n/2;
			long long ans=0;
			for(int i=0;i<p;i++){
				long long k=a[i].y>a[i].z?a[i].y:a[i].z;
				ans+=k;
			}
			for(int i=p;i<n;i++){
				ans+=a[i].mx;
			}
			cout<<ans<<endl;
		}
		else if(f[2]>n/2){
			long long p=f[2]-n/2;
			long long ans=0;
			long long m=0;
			for(int i=0;i<n;i++){
				if(a[i].mi==2&&m<p){
					long long k=a[i].x>a[i].z?a[i].x:a[i].z;
					ans+=k;m++;
				} else{
					ans+=a[i].mx;
				}
			}
			cout<<ans<<endl;
		}
		else if(f[3]>n/2){
			long long p=f[3]-n/2;
			long long ans=0,m=0;
			for(int i=0;i<n;i++){
				if(a[i].mi==3&&m<p){
					long long k=a[i].y>a[i].x?a[i].y:a[i].x;
					ans+=k;m++;
				} else{
					ans+=a[i].mx;
				}
			}
			cout<<ans<<endl;
		}
		else{
			long long ans=0;
			for(int i=0;i<n;i++){
				ans+=a[i].mx;
			}
			cout<<ans<<endl;
		}
		
	} 
	fclose(stdin);
	fclose(stdout);
}

