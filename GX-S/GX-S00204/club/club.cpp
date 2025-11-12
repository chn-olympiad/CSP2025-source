#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,c=0;
	cin>>t;
	for(int i=0;i<t;i++){
		int a[t][3];
		cin>>n;
		for(int j=0;j<n;j++){
			for(int b=0;b<3;b++){
				cin>>a[j][b];
				}
			}
				for (int d = 0;d<n;d++){
				if(	a[d][0]<=a[d][1] and a[d][1]<=a[d][2]){
					c=c+a[d][2];
					}
				if(	a[d][0]>=a[d][1] and a[d][1]>=a[d][2]){
					c=c+a[d][0];
					}
				if(	a[d][0]<=a[d][1] and a[d][1]>=a[d][2]){
					c=c+a[d][1];
					}
				if(	a[d][0]>=a[d][1] and a[d][1]<=a[d][2]){
					if(a[d][0]>=a[d][2]){c=c+a[d][0];}
					if(a[d][0]<=a[d][2]){c=c+a[d][2];}
					}					
				}
				cout<<c<<endl;
				c=c-c;
				}
			}
		
