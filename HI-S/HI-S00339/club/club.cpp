#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,n,sum=0,k=0,realsum=0;
	int m[100005][3];
	int z[6]={0};
	cin>>t;
	for(int i=0;i<t;i++){
		for(int x=0;x<100005;x++){
			for(int y=0;y<3;y++){
				m[x][y]=0;
			}
		}
		n=0;
		cin>>n;
		for(int a=0;a<n;a++){
			for(int j=0;j<3;j++){
				cin>>m[a][j];
				if(m[a][j]>sum){
					sum=m[a][j];
				}
			}
			realsum+=sum;
			sum=0;
		}
	    z[k++]=realsum;
		realsum=0;
		sum=0;	
	}
	for(int i=0;i<t;i++){
		cout<<z[i]<<endl;
	}
    fclose(stdin);
    fclose(stdout); 
	return 0;
} 
