#include<bits/stdc++.h>
using namespace std;
int n,z;
int a[1000000][10],b[1000000][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	z=n/2;
	while(n--){
		int s1,s2,s3,t1,t2,t3;
		int p;
		cin>>p;
		for(int i=1;i<=p;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=p;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				
					s1+=a[i][1];
				
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				
					s2+=a[i][2];
				
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				
					s3+=a[i][3];
				
			}
		}
		cout<<s1+s2+s3-1<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
				b[i][j]=0;
			}
		}
		s1=0,s2=0;s3=0,t1=0,t2=0,t3=0;
	}
	return 0;
}
