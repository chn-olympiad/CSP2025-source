#include<bits/stdc++.h>
using namespace std;
double n,k,qwe,b,a[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2][2],c[2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2][2];;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		if(a[i][0]==k){
			qwe++;
			a[i][1]=1;
		}
		c[i][1]=a[i][1];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			c[i][0]=a[i][0];
			bool er=1;
			for(int z=i+1;z<=j;z++){
				if(c[z][1]==1||c[z-1][1]==1){
					er=0;
					break;
				}
				c[z][0]=(int(c[z-1][0]) | int(a[z][0]))-(int(c[z-1][0]) & int(a[z][0]));
			}
			if(c[j][0]==k && er){
				for(int z=i;z<=j;z++)c[z][1]=1;
				qwe++;
			}
		}
	}
	cout<<qwe;
	return 0;
}
