#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","t",stdin);
	freopen("club.out","w",stdout);
	int n,m,a[100010][5],x=0,y=0,z=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				if(k==3){
					if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]){
					x++;
						if(x<=m/2){
	                        c+=a[j][1];
                        }
					}else if(a[j][2]>a[j][1]&&a[j][2]>a[j][3]){ 
					y++;
						if(y<=m/2){
	                        c+=a[j][2];
                        }
					}else if(a[j][3]>a[j][2]&&a[j][3]>a[j][1]){
					z++;
						if(z<=m/2){
	                        c+=a[j][3];
                        }
					}
				}
			}
		}
		cout<<c<<endl;
		x=0,y=0,x=0,c=0;
	}
	return 0;
} 
/*

*/
