#include <bits/stdc++.h>
using namespace std;
int t,n,a[100010][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=0;p<t;p++){
		int a1[50010],a2[50010],a3[50010],b1[50010],b2[50010],b3[50010],c[100010],ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j]; 
			}
		}
		for(int i=1;i<=n;i++){
			a1[i]=a[i][1];
			a2[i]=a[i][2];
			a3[i]=a[i][3];
			b1[i]=a1[i];
			b2[i]=a2[i];
			b3[i]=a3[i];
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				int x=0;
				if(b1[j]>b1[j-1]){
					x=b1[j];
					b1[j]=b1[j-1];
					b1[j-1]=x;
				}
			}
		}for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				int x=0;
				if(b2[j]>b2[j-1]){
					x=b2[j];
					b2[j]=b2[j-1];
					b2[j-1]=x;
				}
			}
		}for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				int x=0;
				if(b3[j]>b3[j-1]){
					x=b3[j];
					b3[j]=b3[j-1];
					b3[j-1]=x;
				}
			}
		}
		
		for(int j=1;j<=n/2;j++){
			c[j]=b1[j];
			c[j+n/2]=b2[j];
			c[j+2*(n/2)]=b3[j];
		}
		for(int i=2;i<=3*(n/2);i++){
			for(int j=2;j<=3*(n/2);j++){
				int x=0;
				if(c[j]>c[j-1]){
					x=c[j];
					c[j]=c[j-1];
					c[j-1]=x;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=c[i]+ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}

