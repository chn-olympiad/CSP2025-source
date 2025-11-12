#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s,t;
	cin>>t;
	cin>>n;
	int d[101];
	int q=0;
	int w=0;
	int e=0;
	for(int j=1;j<=t;j++){
		for(int i=1;i<=n;i++){
			int a[i],b[i],c[i];
			cin>>a[i]>>b[i]>>c[i];	
			if(a[i]>=b[i]){
				if(a[i]>=c[i]){
					if(q<=n/2&&w<=n/2&&e<=n/2){
						a[i]+=q;
					}
					if(b[i]>c[i]){
						if(q>=n/2&&w>=n/2){
							b[i]+=e;
						
						}
						
					}
				else if(q>=n/2&&e>=n/2){
					c[i]+=w;
				}
				}
			}	
			if(b[i]>=a[i]){
				if(q<=n/2&&w<=n/2&&e<=n/2){
					b[i]+=q;
				}
				if(b[i]>=c[i]){
					if(q>=n/2&&w>=n/2){
						b[i]+=e;
					}
				}
				if(a[i]>c[i]){
					if(q>=n/2&&e>=n/2){
						a[i]+=w; 
					}
				}
				else if(a[i]<c[i]){
					c[i]+=e;
				}
			if(b[i]>=c[i]){
				if(q<=n/2&&w<=n/2&&e<=n/2){
					b[i]+=q;
				}
				if(b[i]>=a[i]){
					if(q>=n/2&&w>=n/2){
						b[i]+=e;	
					}	
				}
				if(a[i]>b[i]){
					if(q>=n/2&&e>=n/2){
						a[i]+=w;
					}
				}
			}		
		}
		d[i]==q+w+e;
	
	}
	sort(d,d+n);
}
cout<<q+w+e<<endl;	
} 

