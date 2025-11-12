#include<bits/stdc++.h>
using namespace std;
int t;
int x[100005];
int y[100005];
int z[100005];
int x_1,y_1,z_1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		x_1=0;
		y_1=0;
		z_1=0;
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>x[j]>>y[j]>>z[j];
			if(x[j]>y[j] && x[j]>z[j] && x_1<n/2){ //x[j]最大 
				x[0]=x[0]+x[j];
				x_1++;
			}
			if(x[j]<y[j] && y[j]>z[j] && y_1<n/2){ //y[j]最大 
				y[0]=y[0]+y[j];
				y_1++;
			}
			if(x[j]<z[j] && y[j]<z[j]  && z_1<n/2){ //z[j]最大 
				z[0]=z[0]+z[j];
				z_1++;
			}
		}
	}
	cout<<x[0]<<" "<<y[0]<<" "<<z[0];
	fclose(stdin);
	fclose(stdout);
    return 0;
}
