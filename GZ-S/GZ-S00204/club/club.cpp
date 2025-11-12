//GZ-S00204 贵阳市第一中学 曹玄憬
#include<bits/stdc++.h>
using namespace std;
int T,n,ans,w;
int a[150005][4],x;
void ec(int b,int c,int d)//b=第几个,c原组,d现组 
{
	for(int i=1+n/2*(d-1);i<=n/2*d;i++){
		if(a[i][d]-a[i][c]<a[b][d]-a[b][c]){
			x=a[b][1];
			a[b][1]=a[i][1];
			a[i][1]=x;
			x=a[b][2];
			a[b][2]=a[i][2];
			a[i][2]=x;
			x=a[b][3];
			a[b][3]=a[i][3];
			a[i][3]=x;
			w=1;
		}
	}
	w=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=n+1;i<=n+n/2;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
		
		for(int i=1;i<=n/2;i++){
			if(a[i][1]<a[i][2]){
				ec(i,1,2);
				if(w==0)
				{
					continue;
				}
			}
			if(a[i][1]<a[i][3]){
				ec(i,1,3);
				if(w==0)
				{
					continue;
				}
			}
		}
		
		for(int i=n/2+1;i<=n;i++){
			if(a[i][2]<a[i][1])
			{
				ec(i,2,1);
				if(w==0)
				{
					continue;
				}
			}
			if(a[i][2]<a[i][3]){
				ec(i,2,3);
				if(w==0){
					continue;
				}
			}
		}
		
		for(int i=n+1;i<=n+n/2;i++){
			if(a[i][3]<a[i][1]){
				ec(i,3,1);
				if(w==0){
					continue;
				}
			}
			if(a[i][3]<a[i][2]){
				ec(i,3,2);
				if(w==0){
					continue;
				}
			}
		}	
		for(int i=1;i<=n/2;i++){
			if(a[i][1]<a[i][2]){
				ec(i,1,2);
				if(w==0)
				{
					continue;
				}
			}
			if(a[i][1]<a[i][3]){
				ec(i,1,3);
				if(w==0)
				{
					continue;
				}
			}
		}
		
		for(int i=n/2+1;i<=n;i++){
			if(a[i][2]<a[i][1])
			{
				ec(i,2,1);
				if(w==0)
				{
					continue;
				}
			}
			if(a[i][2]<a[i][3]){
				ec(i,2,3);
				if(w==0){
					continue;
				}
			}
		}
		
		for(int i=n+1;i<=n+n/2;i++){
			if(a[i][3]<a[i][1]){
				ec(i,3,1);
				if(w==0){
					continue;
				}
			}
			if(a[i][3]<a[i][2]){
				ec(i,3,2);
				if(w==0){
					continue;
				}
			}
		}	
		for(int i=1;i<=n/2;i++){
			ans+=a[i][1];
		}
		for(int i=n/2+1;i<=n;i++)
		{
			ans+=a[i][2];
		}
		for(int i=n+1;i<=n+n/2;i++)
		{
			ans+=a[i][3];
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
