#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t,n,ans[5]={0},a[200][3]={0},b1,b2,b3,c1[200]={0},c2[200]={0},c3[200]={0},d1[200]={0},d2[200]={0},d3[200]={0};
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		b1=b2=b3=ans[t]=0;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]>=a[j][1]&&a[j][0]>=a[j][2]){
				c1[b1]=a[j][0];
				ans[i]+=a[j][0];
				if(a[j][1]>=a[j][2]){
					d1[b1]=a[j][0]-a[j][1];
				}
				else{
					d1[b1]=a[j][0]-a[j][2];
				}
				b1++;
			}
			else if(a[j][1]>=a[j][2]){
				c2[b2]=a[j][1];
				ans[i]+=a[j][1];
				if(a[j][2]>=a[j][0]){
					d2[b2]=a[j][1]-a[j][2];
				}
				else{
					d2[b2]=a[j][1]-a[j][0];
				}
				b2++;
			}
			else{
				c3[b3]=a[j][2];
				ans[i]+=a[j][2];
				if(a[j][0]>=a[j][1]){
					d3[b3]=a[j][2]-a[j][0];
				}
				else{
					d3[b3]=a[j][2]-a[j][1];
				}
				b3++;
			}
		}
		if(b1>n/2){
			sort(d1,d1+b1);
			for(int k=0;k<b1-n/2;k++){
				ans[i]-=d1[k];
			}
		}
		else if(b2>n/2){
			sort(d2,d2+b2);
			for(int k=0;k<b2-n/2;k++){
				ans[i]-=d2[k];
			}
		}
		else if(b3>n/2){
			sort(d3,d3+b3);
			for(int k=0;k<b3-n/2;k++){
				ans[i]-=d3[k];
			}
		}
		//cout<<ans[i]<<endl;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
}
