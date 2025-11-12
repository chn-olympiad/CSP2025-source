#include<iostream>
#include<cstdio>
using namespace std;
int t,m[6]={},mx=-1,num;
int a[6][10001],b[4]={},n[6];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				if(a[j][k]>mx){
					mx=a[j][k];
					num=k;
				}
		    }
		    if(b[num]>n[i]/2){
		    	if(num==1){
		    		if(a[j][2]>a[j][3]){
		    			mx=a[j][2];
		    			b[2]++;
					}else{
						mx=a[j][3];
						b[3]++;
					}
				}
				if(num==2){
		    		if(a[j][1]>a[j][3]){
		    			mx=a[j][1];
		    			b[1]++;
					}else{
						mx=a[j][3];
						b[3]++;
					}
				}
				if(num==3){
		    		if(a[j][1]>a[j][2]){
		    			mx=a[j][1];
		    			b[1]++;
					}else{
						mx=a[j][2];
						b[2]++;
					}
				}
			}else{
				b[num]++;
		        m[i]+=mx;
			}
		    mx=-1;
		}
		int b[4]={};
		int a[6][10001]={};
	}
	for(int i=1;i<=t;i++){
		cout<<m[i]<<endl;
	}
	return 0;
}
