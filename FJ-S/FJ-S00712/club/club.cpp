#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x,y,z;
	int s;
	cin>>s;
	int b[s]={0};
	for(int e=1;e<=s;e++){
		cin>>n;
		int a[n][3]={0};
		for(int i=1;i<=n;i++){
			x=0;
			y=0;
			z=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==3){
					if(a[i][j]>=a[i][j-2]&&a[i][j]>=a[i][j-1]){
						x=a[i][j];
						y=y+x;
						b[e]=b[e]+y;
						z=z+1;
						if(z>n/2){
							b[e]=b[e]-y;
							if(a[i][j-1]<=a[i][j]&&a[i][j-1]>=a[i][j-2]){
								b[e]=b[e]+a[i][j-1];
							}
							else if(a[i][j-2]<=a[i][j]&&a[i][j-2]>=a[i][j-1]){
								b[e]=b[e]+a[i][j-2];
							}
						}
					}
					else if(a[i][j-1]>=a[i][j-2]&&a[i][j-1]>=a[i][j]){
						x=a[i][j-1];
						y=y+x;
						b[e]=b[e]+y;
						z=z+1;
						if(z>n/2){
							b[e]=b[e]-y;
							if(a[i][j]<=a[i][j-1]&&a[i][j]>=a[i][j-2]){
								b[e]=b[e]+a[i][j];
							}
							else if(a[i][j-2]<=a[i][j-1]&&a[i][j-2]>=a[i][j]){
								b[e]=b[e]+a[i][j-2];
							}
					}}
					else{
						x=a[i][j-2];
						y=y+x;
						b[e]=b[e]+y;
						z=z+1;
						if(z>n/2){
							b[e]=b[e]-y;
							if(a[i][j-1]<=a[i][j-2]&&a[i][j-1]>=a[i][j]){
								b[e]=b[e]+a[i][j-1];
							}
							else if(a[i][j]<=a[i][j-2]&&a[i][j]>=a[i][j-1]){
								b[e]=b[e]+a[i][j];
							}}
					}
				}
			}
		}
	}
	for(int e=1;e<=s;e++){
		cout<<b[e]<<endl;
	}
	return 0;
}
