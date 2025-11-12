#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;
	cin>>m;
	int num[m]={};
	for(int j=0;j<m;j++){
	int n;
	cin>>n;
	int a[n],b[n],c[n],c1=0,c2=0,c3=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				if(c1>n/2) {
				    if(b[i]>c[i]){
				    	c2++;
				    	num[j]+=b[i];
					}
					if(c[i]>b[i]){
						c3++;
						num[j]+=c[i];
					}
				}else{
					c1++;
					num[j]+=a[i];
				}
			}else if(b[i]>a[i]&&b[i]>c[i]){
				if(c2>n/2) {
				    if(a[i]>c[i]){
				    	c1++;
				    	num[j]+=a[i];
					}
					if(c[i]>a[i]){
						c3++;
						num[j]+=c[i];
					}
				}else{
					c2++;
					num[j]+=b[i];
				}
			}else if(c[i]>b[i]&&c[i]>a[i]){
				if(c3>n/2) {
			   		if(a[i]>b[i]){
				    	c1++;
				    	num[j]+=a[i];
					}
					if(b[i]>a[i]){
						c2++;
						num[j]+=b[i];
					}
				}else{
					c3++;
					num[j]+=c[i];
				}	
			}
		}	
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<endl;
	}
}
