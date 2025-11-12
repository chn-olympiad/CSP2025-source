#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,x=0,y=0,z=0,sum=0;
	cin>>t;
	for(int k=1; k<=t; k++){
		sum=0;
		x=0;
		y=0;
		z=0;
		int n,a[100010]={},b[100010]={},c[100010]={};
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for(int i=n; i>0; i--){
			if(a[i]>b[i]&&a[i]>c[i]&&x<n/2){
				sum+=a[i];
				x++;
			}
			else if(b[i]>a[i]&&b[i]>c[i]&&y<n/2){
				sum+=b[i];
				y++;
			}
			else if(c[i]>a[i]&&c[i]>b[i]&&z<n/2){
				sum+=c[i];
				z++;
			}
			else if(x<y&&x<z&&x<n/2){
				sum+=a[i];
				x++;
			}
			else if(y<x&&y<z&&y<n/2){
				sum+=b[i];
				x++;
			}
			else if(z<n/2){
				sum+=c[i];
				z++;
			}
			else if(x<n/2){
				sum+=a[i];
				x++;
			}
			else if(y<n/2){
				sum+=b[i];
				y++;
			}
		}
	cout<<sum<<endl;
	}
	return 0;
}
