#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,a[10001][1001],b[10001],x,y,z,mx;
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n;
		x=0;y=0;z=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]=max(a[i][1],max(a[i][2],a[i][3])); 
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(b[i]==a[i][1]) x++;
				else if(b[i]==a[i][2]) y++;
				else z++;
			}if(x<n/2&&y<n/2&&z<n/2){
				mx-=2;
			}cout<<mx;
		}
	}
	return 0;
} 
