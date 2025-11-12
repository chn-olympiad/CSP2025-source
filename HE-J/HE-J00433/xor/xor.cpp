#include<bits/stdc++.h> 
using namespace std;
int n,k2,a[500010],b[500010][24],e[500010][24],ji=0,h=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k2;
	int bj[n];
	for(int i=1;i<=n;i++){
		bj[i]=0;
		cin>>a[i];
		int c=1;
		if(a[i]==0)b[i][c]=0;
		while(a[i]!=0){
			b[i][c]=a[i]%2;
			a[i]/=2;
			c++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int d=0,pd=0,pd2=1;
			for(int k=i;k<=j;k++){
				pd=1;
				for(int l=1;l<=24;l++){
					e[h][l]+=b[k][l];
				}
				for(int l=1;l<=24;l++){
					if(e[h][l]%2!=0){
						e[h][l]=1;
					}
					else{
						e[h][l]=0;	
					}
				}
			}
			for(int l=1;l<=24;l++){
				d+=e[h][l]*pow(2,l-1);
			}
			h++;
			for(int k=i;k<=j;k++){
				if(bj[k]==1)pd2=0;
			}
			if(d==k2&&pd2==1&&pd==1){
				for(int k=i;k<=j;k++){
					bj[k]=1;
				}
				ji++;
			}
		}
	}
	cout<<ji;
	return 0; 
}
