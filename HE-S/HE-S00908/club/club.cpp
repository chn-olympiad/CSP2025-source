#include<bits/stdc++.h>
using namespace std;int t,n,x,y=0,a[10005][10005],b,c,z;
int main(){	
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

cin>>t;
	for(int h=1;h<=t;h++){
	x=0;y=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				if(x<a[i][j]&&b<=n/2&&c<=n/2&&z<=n/2){
					if(j==1)b++;
					else if(j==2) c++;
					else z++;
					x=a[i][j];
				}
		
	}y+=x;
	}cout<<y<<endl;}
return 0;}
