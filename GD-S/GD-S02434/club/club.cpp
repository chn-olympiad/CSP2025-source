#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,h=0,o=0;
		cin>>n;
		int a[n][3];
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				cin>>a[j][z];
			}
		}
		for(int p=0;p<3;p++){
			o=0;
			int b[3]={0,0,0};
			for(int j=0;j<n;j++){
				int d=0;
				for(int z=0;z<3;z++){
					d=max(d,a[j][z]);
				}
				for(int z=0;z<3;z++){
					if(b[z]<n/2 && d==a[j][z]){
						a[j][z]=0;
						b[z]+=1;
						o+=d;
					}
				}
			}
			h=max(h,o);
		}
		cout<<h;
	}
	return 0;
}
