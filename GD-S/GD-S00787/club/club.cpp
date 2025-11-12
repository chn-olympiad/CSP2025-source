#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],d,e,f,g;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		d=0;
		e=0;
		f=0;
		g=0;
		for(int j=1;j<=n;j++)cin>>a[j]>>b[j]>>c[j];	
		for(int j=1;j<=n;j++){
			if(a[j]>=b[j] && a[j]>=c[j] && d<n/2 || e>=n/2 && f>=n/2 && d<n/2){
				d++;
				g=g+a[j];				
			}else if(b[j]>=a[j] && b[j]>=c[j] && e<n/2 || d>=n/2 && f>=n/2 && e<n/2){
				e++;
				g=g+b[j];
			}else{
				f++;
				g=g+c[j];
			}
		}
		cout<<g<<endl;
	}
	return 0;
}
