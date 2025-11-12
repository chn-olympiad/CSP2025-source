#include <iostream>
#include <cstdio>
using namespace std;
int a[300]; 
int b[300];
int c[300];
int d[300],e[300],f[300],m[300],kll;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	
	int att=0,btt=0,ctt=0;
	int ik,ok,pk;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>c[j]){
				d[j]=a[j];
				att++;
			}else if(b[j]>=a[j]&&b[j]>=c[j]){
				e[j]=b[j];
				btt++;
			}else if(c[j]>=b[j]&&c[j]>=a[j]){
				f[j]=c[j];
				ctt++;
			}
		}
		if(n==2){
			if(d[i]>d[i+1]&&d[i+1]!=0){
				if(b[i+1]>c[i+1]){
					cout<<a[i]+b[i+1];
					return 0;
				}else{
					cout<<a[i+1]+b[i];
					return 0;
				}
			}
		}
		if(att>n/2){
				for(int k=1;att>n/2;k++){
					ik=d[k];
					for(int p=k;p<=att;p++){
						if(ik<=d[p]){
							e[btt+p]=ik;
							d[k]=0;
							att--;
						}else if(ik>d[p]){
							p++;
							ik=d[k+1];
							e[btt+p]=ik;
							d[k+1]=0;
							att--;
						}
					}
				}
			}else if(btt>n/2){
				for(int k=1;btt>n/2;k++){
					ok=e[k];
					for(int p=k+1;p<=btt;p++){
						if(ok<e[p]){
							f[ctt+p]=ok;
							e[k]=0;
							btt--;
						}else if(ok>e[p]){
							ok=e[k+1];
							f[ctt+p]=ok;
							e[k+1]=0;
							btt--;
						}
					}
				}
			}else if(ctt>n/2){
				for(int k=1;ctt>n/2;k++){
					pk=f[k];
					for(int p=k+1;p<=ctt;p++){
						if(pk<d[p]){
							d[btt+p]=pk;
							f[k]=0;
							ctt--;
						}else if(pk>e[p]){
							pk=f[k+1];
							d[btt+p]=pk;
							f[k+1]=0;
							ctt--;
						}
					}
				}
			}
			for(int l=1;l<=n;l++){
				for(int g=1;g<=n/2;g++){
					kll+=d[g];
				}
				for(int g=1;g<=n/2;g++){
					kll+=e[g];
				}
				for(int g=1;g<=n/2;g++){
					kll+=f[g];
				}
			}
			m[i]=kll;
	}
	for(int i=1;i<=t;i++){
		cout<<m[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
