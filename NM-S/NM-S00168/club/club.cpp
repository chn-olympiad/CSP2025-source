#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t,n;
	int a[100001][3],b[3]={0,0,0},d[3]={0,0,0};
	cin>>t;
	for(int i=0;i<t;i++){
		int ans=0;
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				if(a[j][k]>=b[k]){
					d[k]+=1;
					b[k]=a[j][k];
					if(d[k]<=n/2){
						ans+=b[k];
					}
				}
			}
		}cout<<ans<<endl;
	}fclose(stdin);
    fclose(stdout);
    return 0;
}
