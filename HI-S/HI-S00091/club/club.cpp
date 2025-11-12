#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in",r,"stdin");
	freopen("club.out",w,"stdout");
	int t,n,a[101][6],cnt=0;
	int x=0,y=0,z=0;
	int ax[101],ay[101],az[101],c[101];
	int xx=0,yy=0,zz=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int s;
		s=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int k=1;k<=n;k++){
			if(a[k][1]>=a[k][2] && a[k][1]>=a[k][3]){
				ax[k]=a[k][1];
				cnt=cnt+a[k][1];
				x++;
				
			}
			else if(a[k][2]>=a[k][1] && a[k][2]>=a[k][3]){
				ay[k]=a[k][2];
				cnt=cnt+a[k][2];
				y++; 
			} 
			else if(a[k][3]>=a[k][1] && a[k][3]>=a[k][2]){
				az[k]=a[k][3];
				cnt=cnt+a[k][3];
				z++;
			}
		}
		
		c[i]=cnt;
	}
	for(int i=1;i<=t;i++){
		cout<<c[i]<<endl;
	}
	
	return 0;
} 
