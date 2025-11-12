#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
} 
int n,m;
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>m;
	int l[m];
	for(int q=0;q<n;q++){
		cin>>n;
		int a[n][3],b[n/2][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int max1=0,max2=0,x;
			for(int i=0;i<n;i++){
				for(int j=0;j<3;j++){
					int c=max1;
					max1=max(max1,a[i][j]);
					if(c!=max1){
						x=i;
					}
				}
			}
			for(int i=0;i<n;i++){
				for(int j=1;j<3;j++){
					int c=max2;
					max2=max(max2,a[i][j]);
				}
			}cout<<max1+max2;
		}else{
			int c[n];
			for(int i=0;i<n;i++){
				c[i]=a[0][i];
			}sort(c,c+n,cmp);
			int w=0;
			for(int i=0;i<n/2;i++){
				w+=c[i];
			}cout<<w;
		}
	}
} 
