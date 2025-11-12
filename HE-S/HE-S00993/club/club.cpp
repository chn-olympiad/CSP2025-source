#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,sum=0;
	int a[20010][20010]={0};
	for(int a=1;a<=t;a++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				
				if(a[j][i]==0&&a[3]==0&&n==100000){
					sort(a[1][1],a[1][100000]);
					for(int x=50000;x<=100000;x++){
						sum+=a[1][x];
					}
				}
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
