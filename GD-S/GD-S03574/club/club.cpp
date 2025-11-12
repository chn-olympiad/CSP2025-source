#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int k,a[10005][4],n[10005][4],m[4][4];
		cin>>k;
		for(int j = 1;j <= k;j++){
			int yu[4][4];
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			for(int d1=1;d1<=3;d1++){
				for(int d2 = 1;d2<=3;d2++){
					yu[d1][d2]=m[d1][d2];
				}
			}
			for(int y=1;y <= 3;y++){
				if(n[j-1][1]>max(n[j-1][2],n[j-1][3]) == n[j-1][1]){
					if(m[y][1]<k/2){
						n[j][y] = n[j-1][1]+a[j][y];
						yu[y][1] = m[y][1]+1;
					}
					else if(n[j-1][2] > n[j-1][3]){
						if(m[y][2] < k/2){
							n[j][y] = n[j-1][2] + a[j][y];
							yu[y][2] = m[y][2] + 1;
						}
						else{
							n[j][y] = n[j-1][3]+a[j][y];
							yu[y][3]=m[y][3] + 1;
						}	
					}
				}else if(max(max(n[j-1][1],n[j-1][2]),n[j-1][3])==n[j-1][2]){
					if(m[y][2]<k/2){
						n[j][y] = n[j-1][2]+a[j][y];
						yu[y][2] = m[y][2]+1;
					}
					else if(n[j-1][1] > n[j-1][3]){
						if(m[y][1] < k/2){
							n[j][y] = n[j-1][1] + a[j][y];
							yu[y][1] = m[y][1] + 1;
						}else{
							n[j][y] = n[j-1][3]+a[j][y];
							yu[y][3]=m[y][3] + 1;
						}
						
					}	
				}else{
					if(m[y][3]<k/2){
						n[j][y] = n[j-1][3]+a[j][y];
						yu[y][3] = m[y][3]+1;
					}
					
					else if(n[j-1][1] > n[j-1][2]){
						if(m[y][1] < k/2){
							n[j][y] = n[j-1][1] + a[j][y];
							yu[y][1] = m[y][1] + 1;
						}else{
							n[j][y] = n[j-1][2]+a[j][y];
							yu[y][2]=m[y][2] + 1;
						}	
					}
					
				}
				
				
			}
			for(int d1=1;d1<=3;d1++){
				for(int d2 = 1;d2<=3;d2++){
					m[d1][d2]=yu[d1][d2];
				}
			}
			
		}	
		cout<<max(n[k][1],max(n[k][2],n[k][3]));
	}
	return 0;
}
