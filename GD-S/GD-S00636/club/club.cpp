#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,a[N][3],m,b[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		m=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n==2){
			for(int i=0;i<3;i++){
				b[i]++;
				for(int j=0;j<3;j++){
					b[j]++;
					if(b[0]<=1&&b[1]<=1&&b[2]<=1){
						m=max(m,a[0][i]+a[1][j]);
					}
					b[j]--;
				}
				b[i]--;
			}
			cout<<m<<"\n";						
		}
		else if(n==4){
			for(int i=0;i<3;i++){
				b[i]++;
				for(int j=0;j<3;j++){
					b[j]++;
					for(int k=0;k<3;k++){
						b[k]++;
						for(int l=0;l<3;l++){
							b[l]++;
							if(b[0]<=2&&b[1]<=2&&b[2]<=2){
								m=max(m,a[0][i]+a[1][j]+a[2][k]+a[3][l]);
							}
							b[l]--;
						}
						b[k]--;
					}
					b[j]--;
				}
				b[i]--;
			}
			cout<<m<<"\n";						
		}
    }
	return 0;
}
