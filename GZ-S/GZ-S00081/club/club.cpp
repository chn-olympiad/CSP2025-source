//GZ-S00081 遵义市新蒲新区滨湖中学 向雨晨 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[100005][4];
	cin>>t;
	for(int i = 1;i<=t;i++){
		cin>>n;
		int x = 0,y = 0,z = 0;
		for(int i = 1;i<=n;i++){
			for(int j= 1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int sum1 = 0,sum2 = 0,sum3 = 0,num = 0;
		for(int i= 1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]&&sum1<=n/2){
				sum1++;
				num+=a[i][1];
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]&&sum2<=n/2){
				sum2++;
				num+=a[i][2];
			}
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]&&sum3<=n/2){
				sum3++;
				num+=a[i][3];
			}
		}
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
