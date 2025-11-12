#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n,a[3][100000],t,x1=0,x2=0,x3=0,sum=0,m,N;
		cin>>n;
		N=n/2;
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++){
				cin>>a[j][z];
				}
			}
		for(int j=0;j<n;j++){
				int t1,t2,t3;
				t1=a[j][0];t2=a[j][1];t3=a[j][2]; 
				if(t1>max(t2,t3)){
					t=t1;
				}
				else{
					t=max(t2,t3);
				} 
				sum=sum+t;
				if(t==0) x1++;
				if(t==1) x2++;
				if(t==2) x3++;
		}
		if(x1>max(x2,x3)){
					m=x1;
				}
				else{
					m=max(x2,x3);
				} 
		if(m<=n/2){
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
