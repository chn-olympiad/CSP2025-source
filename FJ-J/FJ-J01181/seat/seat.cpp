#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n = 0,m = 0;
	int a[110];
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++)
		cin>>a[i];
	int seat[n][m],n1 = 0,m1 = 0,maxx = 0;
	for(int i = 1;i <= m;i++){
		maxx = 0;
		for(int j = m%2==1 ? 1 : n; m%2==1 ? j<=n : j>=1; m%2==1 ? j++ : j--){
			for(int k = 1;k <= n*m;k++)
				if(a[k] >= maxx) maxx = a[k];
			if(maxx!=0){
				if(maxx == a[1]){
					cout<<n1<<m1;
					break;
				}
				maxx = seat[n1][m1];
				if(maxx == seat[n1][m1]){
					n1++;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
