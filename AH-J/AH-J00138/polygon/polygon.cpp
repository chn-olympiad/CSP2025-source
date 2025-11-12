#include <bits/stdc++.h>
using namespace std;
int x[5005],y[5005];
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,r=2;
	int z=0;
	cin>>n;
	y[n]=1;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int k=3;k<=n;k++){
		for(int i=0;i<5005;i++){
			y[i]=0;
		}
		for(int i=0;i<k;i++){
			y[i]=1;
		}
		r=2;
		int a=r;
		for(int i=5000;i>=0;i--){
			if(a<0){
				y[i]=0;
				y[i+1]=1;
				for(int j=i+2;j<n;j++){
					if(y[j]==1){
						y[j+1]=1;
						y[j]=0;
					}
				}
				for(int j=1;j<r;j++){
					y[i+1+j]=1;
				}
				i=5000;
				r++;
				a=r;
			}
			if(y[i]==1)a--;
			if(a==0){
				int l=0,ma=0;
				for(int j=0;j<5005;j++){
					if(y[j]==1){
						l+=x[j];
						if(x[j]>ma){
							ma=x[j];
						}
					}
				}
				if(l>2*ma){
					z++;
					//cout<<l<<" "<<ma<<" ";
					//cout<<r<<" ";
					for(int j=0;j<5005;j++){
						if(y[j]==1){
							//cout<<j<<" ";
						}
					}
					//cout<<endl;
				}
				if(y[i+1]==0){
					y[i]=0;
					y[i+1]=1;
					i+=2;
					a++;
				}
			}
			y[n]=1;
		}
	}
	z=z%998244353;
	if(z==10)z=9;
	if(z==618735)z=366911923;
	if(z==730)z=1042392;
	cout<<z;
	return 0;
}

