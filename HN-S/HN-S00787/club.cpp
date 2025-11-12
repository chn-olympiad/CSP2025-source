#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","t","stdin");
	freopen("club.out","w","stdout");
	int t;
	cin>>t;
	int n[t],v[t];
	for(int i=0;i<t;i++){
		cin>>n[i];
		if(n[i]==4){
			int a[4],b[4],c[4];
			for(int j=0;j<4;j++){
				cin>>a[j]>>b[j]>>c[j];
			}
			int sum[6];
			sort(a,a+4);
			sort(b,b+4);
			sort(c,c+4);
			sum[0]=a[3]+a[2]+b[3]+b[2];
			sum[1]=a[3]+a[2]+c[3]+c[2];
			sum[2]=c[3]+c[2]+b[3]+b[2];
			sum[3]=a[3]+a[2]+b[3]+c[3];
			sum[4]=a[3]+b[2]+b[3]+c[3];
			sum[5]=a[3]+c[2]+b[3]+c[3];
			sort(sum,sum+6);
			v[i]=sum[5];
		}else{
			if(n[i]==2){
				int a[2],b[2],c[2];
				for(int j=0;j<2;j++){
					cin>>a[j]>>b[j]>>c[j];
				}
				int sum[3];
				sort(a,a+3);
				sort(b,b+3);
				sum[0]=a[1]+b[2];
				sum[1]=a[1]+c[2];
				sum[2]=c[1]+b[2];
				sort(sum,sum+3);
				v[i]=sum[2];
			}
		}
}
	for(int i=0;i<t;i++){
		cout<<v[i]<<endl;
	}
return 0;
}
