#include<bits/stdc++.h>
using namespace std;
int t,n;
int bm1,bm2,bm3,my1,my2,my3;
int a[100011][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t!=0){
		bm1=0;bm2=0;bm3=0;my1=0;my2=0;my3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				if(bm1<(n/2)){
					my1+=a[i][1];
				    bm1++;
				}else if(a[i][2]>a[i][3]){
					if(bm2<(n/2)){
						my2+=a[i][2];
				    	bm2++;
					}else if(bm3<(n/2)){
						my3+=a[i][3];
						bm3++;
					}
				}else if(a[i][3]>a[i][2]){
					if(bm3<(n/2)){
						my3+=a[i][3];
				    	bm3++;
					}else if(bm2<(n/2)){
						my2+=a[i][3];
						bm2++;
					}
				}	
			}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				if(bm2<(n/2)){
					my2+=a[i][1];
				    bm2++;
				}else if(a[i][1]>a[i][3]){
					if(bm1<(n/2)){
						my1+=a[i][2];
				    	bm1++;
					}else if(bm3<(n/2)){
						my3+=a[i][3];
						bm3++;
					}
				}else if(a[i][3]>a[i][1]){
					if(bm3<(n/2)){
						my3+=a[i][3];
				    	bm3++;
					}else if(bm1<(n/2)){
						my1+=a[i][3];
						bm1++;
					}
				}
			}else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				if(bm3<(n/2)){
					my3+=a[i][1];
				    bm3++;
				}else if(a[i][2]>a[i][1]){
					if(bm2<(n/2)){
						my2+=a[i][2];
				    	bm2++;
					}else if(bm1<(n/2)){
						my1+=a[i][3];
						bm1++;
					}
				}else if(a[i][1]>a[i][2]){
					if(bm1<(n/2)){
						my1+=a[i][3];
				    	bm1++;
					}else if(bm2<(n/2)){
						my2+=a[i][3];
						bm2++;
					}
				}
			}
		}
		cout<<my1+my2+my3;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
