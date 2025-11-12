#include<bits/stdc++.h>
using namespace;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int m,t,n,a[3][100003],b[200003],n[3],l,min,h,d;
double an;
fool f;
int main(){
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		u=n;
		n/=2;
		for(int m=u;m>0;m--){
			cin>>a[0][m]>>a[1][m]>>a[2][m];
			int z=max(a[0][m],a[1][m],a[2][m]);
			if(f){
				if(a[l][m]!=z) an+=z
				else{
					int p=max(a[h][m],a[d][m])
					if(min>z) an+=p;
					else{
						p=z-p;
						an=an+z-min;
						a[l][p]++;
						for(int i=0;i<p,i++){
							if(a[l][i]) min=i;
							break;
						}
					}
				}
			}
			else {
				an+=z;
				if(a[0][m]==z){
					an+=a[0][m];
					n[0]++;
					if(n[0]==n){
						f=ture;
						l=0;
						h=1;
						d=2;
					}
				}
				else if(a[1][m]==z){
					an+=a[1][m];
					n[1]++;
					if(n[1]==n){
						f=ture;
						l=1;
						h=0;
						d=2;
					}
				}
				else{
					an+=a[2][m];
					n[2]++;
					if(n[2]==n){
						f=ture;
						l=2;
						h=1;
						d=0;
					}
				}
			if(f){
				for(int i=u;i>=n;i--){
					if(max(a[l][i]==max(a[l][i],a[h][i],a[d][i])){
						b[a[l][i]-a[h][i]]++;
						b[a[l][i]-a[d][i]]++;
					}
				}
				for(int i=0;i<2000000;i++){
					if(b[i]){
						min=b[i];
						break;
					}
				}
			}
			}
		}
		cout<<an;
	}
}
