#include <bits/stdc++.h>
using namespace std;
int t,n,a1[4],b1[4];
int b[4],sum;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a1[j];
				b1[j]=a1[j];
			}
			sort(b1+1,b1+n+1);
			for(int j=1;j<=3;j++){
				if(b1[4]==a1[j]){
					if(b[j]<n/2){
						sum+=b1[4];
						b[j]++;
						break;
					}else{
						for(int k=1;k<=3;k++){
							if(b1[3]==a1[k]){
								sum+=b1[3];
								b[k]++;
							}
						}
					}
				}
			}
			
		}
		cout<<sum<<endl;
	}
	return 0;
}
