#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t,n,d[10001],a[10001],b[10001],c[10001],ans,h=0,e=0,m=0,q=0,z=0,x=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		h=0;
		e=0;
		m=0;
		cin>>n;
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>d[1]>>d[2]>>d[3];
			sort(d+1,d+4);
			cout<<d[1]<<d[2]<<d[3]<<endl;
			if(d[1]>d[2] and d[1]>d[3]){
				a[j]=d[1];
				h++;
				if(h<=n/2){
					ans=ans+a[j];
				}
			}
			if(d[2]>d[1] and d[2]>d[3]){
				b[j]=d[2];
				e++;
				if(e<=n/2){
					ans=ans+a[j];
				}
			}
			if(d[3]>d[1] and d[3]>d[2]){
				c[j]=d[3];
				m++;
				if(m<=n/2){
					ans=ans+a[j];
				}
			}		 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
