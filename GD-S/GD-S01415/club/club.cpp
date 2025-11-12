#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		int x=0,y=0,z=0,cnt=0,out=0;
		int d[100100]={0};
		int a[100100]={0},b[100100]={0},c[100100]={0},ans[100100]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>b[i] and a[i]>c[i]){
				ans[i]=1;
				x++;
				d[i]=a[i]-max(b[i],c[i]);
			} 
			else if(b[i]>a[i] and b[i]>c[i]){
				ans[i]=2;
				y++;
				d[i]=b[i]-max(a[i],c[i]);
			}
			else if(c[i]>a[i] and c[i]>b[i]){
				ans[i]=3;
				z++;
				d[i]=c[i]-max(a[i],b[i]);
			}
			 
		}
		if(x>n/2){
		
		while(1){
			x--;
			int m=200000;
			for(int i=1;i<=n;i++){
				if(ans[i]==1 and d[i]<m){
					m=d[i];cnt=i;
					}
			}
			if(b[cnt]>=c[cnt]){
				y++;ans[cnt]=2;
			}
			else if(c[cnt]>b[cnt]){
				z++;ans[cnt]=3;
			}
			if(x<=n/2)break;
		}
		}
		while(y>n/2){
			y--;
			int m=200000;
			for(int i=1;i<=n;i++){
				if(ans[i]==2 and d[i]<m){
					m=d[i];cnt=i;
				}
			}
			if(a[cnt]>=c[cnt]){
				x++;ans[cnt]=1;
			}
			else if(c[cnt]>a[cnt]){
				z++;ans[cnt]=3;
			}
			
		}
		while(z>n/2){
			z--;
			int m=200000;
			for(int i=1;i<=n;i++){
				if(ans[i]==3 and d[i]<m){
					m=d[i];cnt=i;
				}
			}
			if(a[cnt]>=b[cnt]){
				x++;ans[cnt]=1;
			}
			else if(b[cnt]>a[cnt]){
				y++;ans[cnt]=2;
			}
			
		}
		
		for(int i=1;i<=n;i++){
			if(ans[i]==1)out+=a[i];
			else if(ans[i]==2)out+=b[i];
			else if(ans[i]==3)out+=c[i];
		}
		
		cout<<out<<endl;
			
		
	}
	return 0;
} 
