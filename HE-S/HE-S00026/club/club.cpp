#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	int k;
	cin >> k;
	while(k--){
		int n,x=0;
		cin >> n;
		int a[4][n+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int m=0,max2=0,sum[4]={},r=0;
			for(int j=1;j<=3;j++){
				if(m<a[i][j]){
					r=j;
					m=max(m,a[i][j]);
				}
			}
			cout << r << endl;
			sum[r]++;
			if(sum[r]<=n/2){
				x+=m;
			}else{
				for(int j=1;j<=3;j++){
					if(a[i][j]>max2 && a[i][j]<m){
						max2=a[i][j];
					}
				}
				x+=max2;	
			}	
		} 
		cout << x;
	}		
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
