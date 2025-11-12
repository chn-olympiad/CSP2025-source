#include<iostream>
using namespace std;
int main (){
	int t;
	cin>>t;
	while(t--){
		int n;
	    cin>>n;
	    if(n%2!=0){return 0;}
	    int cnt=0;
	    int a[n][3];
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=3;j++){
	    		cin>>a[i][j];
			}
		}int z=n/2;
		int b[n][4]={0,1,2,3},c[n][4]={0,1,2,3},d[n][4]={0,1,2,3};
		for(int i=1;i<=n;i++){
			for(int j=3;j>=1;j--){
				if(j){
					b[z][4]=max(b[z-1][j-1],b[i-1][j-1]+a[i][1]);
				    b[z+(cnt++)][4];
				    if(z+cnt>z){
					    cnt=0;
						continue;
				    }
				}
				
			}
		}for(int i=1;i<=n;i++){
			for(int j=3;j>=1;j--){
				if(j){
					c[z][4]=max(c[z-1][j-1],c[i-1][j-1]+a[i][2]);
				    c[z+(cnt++)][4];
				    if(z+cnt>z){
					    cnt=0;
					    continue;
				    }
				}
				
			}
		}for(int i=1;i<=n;i++){
			for(int j=3;j>=1;j--){
				if(j){
					d[z][4]=max(d[z-1][j-1],d[i-1][j-1]+a[i][3]);
				    d[z+(cnt++)][4];
					if(z+cnt>z){
				    cnt=0;
					continue;	
				    }
				}
			}
		}for(int i=1;i<=1;i++){
				int sum=b[z][4]+c[z][4]+d[z][4];
		        cout<<sum<<endl;
		}	
	}
	return 0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1 
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
}

