#include<bits/stdc++.h>
using namespace std;
int n,t,sum=0;
int x=0,y=0,z=0;
int da=0,da2=0,da1=0,da3=0;
int a[1000005],b[1000005],c[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			int m=max(a[i],b[i]);
			int n=max(m,c[i]);
			sum+=n;
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x++;
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				y++;
			}
			else if(c[i]>=a[i]&&c[i]>=a[i]){
				z++;
			}
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<sum;
		}
	
		else if(x>n/2){
				for(int i=0;i<n;i++){
					da=max(a[i],a[i+1]);
					if(a[i]>a[i+1]){
						da2=max(b[i+1],c[i+1])+a[i];
						da1=max(b[i],c[i])+a[i];
					}
					else {
						da2=max(b[i],c[i])+a[i+1];
						da1=max(b[i+1],c[i+1])+a[i];
					}
				}
				cout<<da2+da1;
		}
		else if(y>n/2){
				for(int i=0;i<n;i++){
					da=max(b[i],b[i+1]);
					if(b[i]>b[i+1]){
						da=max(a[i+1],c[i+1]);
						da2=da+b[i];
						da1=max(a[i],c[i])+b[i];
					}
					else {
						da2=max(a[i],c[i])+b[i+1];
						da1=max(a[i+1],c[i+1]);
					}
				}
				cout<<da2+da1;
		}
		else if(z>n/2){
				for(int i=0;i<n;i++){
					da=max(c[i],c[i+1]);
					if(c[i]>c[i+1]){
						da=max(a[i+1],b[i+1]);
						da2=da+c[i];
						da1=max(a[i],b[i])+c[i];
					}
					else {
						da2=max(a[i],b[i])+c[i+1];
						da1=max(a[i+1],b[i+1]);
					}
				}
				cout<<da2+da1;
		}
	}
	return 0;
}