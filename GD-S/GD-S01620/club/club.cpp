#include <bits/stdc++.h>
using namespace std;
int a[100000][100000],b[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt1=0,cnt2=0,cnt3=0,count=0;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		count=0;
		for (int j=0;j<n;j++){
			for (int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}
		if(a[0][0]+a[1][0]>=count){
			count=(a[0][0]+a[1][0]);
		}
		if(a[0][0]+a[1][1]>=count){
			count=(a[0][0]+a[1][1]);
		}
		if(a[0][0]+a[1][2]>=count){
			count=(a[0][0]+a[1][2]);
		}
		if(a[0][1]+a[1][0]>=count){
			count=(a[0][1]+a[1][0]);
		}
		if(a[0][1]+a[1][1]>=count){
			count=(a[0][1]+a[1][1]);
		}
		if(a[0][1]+a[1][2]>=count){
			count=(a[0][1]+a[1][2]);
		}
		if(a[0][2]+a[1][0]>=count){
			count=(a[0][2]+a[1][0]);
		}
		if(a[0][2]+a[1][1]>=count){
			count=(a[0][2]+a[1][1]);
		}
		if(a[0][2]+a[1][2]>=count){
			count=(a[0][2]+a[1][2]);
		}
		b[i]=count-1;
	}
	for (int i=0;i<t;i++){
		cout<<b[i]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);

}
