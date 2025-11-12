#include<bits/stdc++.h>
using namespace std;
int ji[10087][10087],dp1[10087][10087],n,k,a[10087],maxx,dp2[10087][10087];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int q=0;q<n;q++){
		for(int z=q;z<n;z++){
			int shi=a[q];
			for(int i=q+1;i<=z;i++){
				shi^=a[i];
			}
			if(shi==k){
				dp1[q][z]=1;
				dp2[q][z]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int h=i+1;h<n;h++){
				for(int f=j+1;f<n;f++){
					dp2[h][f]=max(dp2[h][f],dp1[h][f]+dp2[i][j]);
					
				}
			}
		}
	}
	for(int q=0;q<n;q++){
		for(int z=q;z<n;z++){
			maxx=max(maxx,dp2[q][z]);
		}
	}
	cout<<maxx;
	return 0;
}
