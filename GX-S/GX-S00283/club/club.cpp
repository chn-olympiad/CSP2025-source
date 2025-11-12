#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001][4],b[1000001][4],xa,xb,xc,pa,pb,pc,sum,suma,sumb,sumc;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			suma=0;sumb=0;sumc=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
				xa=b[1][1];
				for(int k=1;k<=(n/2);k++){
					if(xa>=b[k][1]){
						xa=b[k][1];
						pa=k;
						}
				}
				if(a[i][1]>=xa){
					suma=abs(a[i][1]-xa);
					}
				xb=b[1][2];
				for(int k=1;k<=(n/2);k++){
					if(xb>=b[k][2]){
						xb=b[k][2];
						pb=k;
						}
				}
				if(a[i][2]>=xb){
					sumb=abs(a[i][2]-xb);
					}

				xc=b[1][3];
				for(int k=1;k<=(n/2);k++){
					if(xc>=b[k][3]){
						xc=b[k][3];
						pc=k;
						}
				}
				if(a[i][3]>=xc){
					sumc=abs(a[i][3]-xc);
					}

			if((suma>=sumb)&&(suma>=sumc)){
				b[pa][1]=a[i][1];
				continue;
			}
			if((sumb>=suma)&&(sumb>=sumc)){
				b[pb][2]=a[i][2];
				continue;
			}
			if((sumc>=sumb)&&(sumc>=suma)){
				b[pc][3]=a[i][3];
				continue;
			}
		}
		for(int k=1;k<=(n/2);k++){
			for(int g=1;g<=3;g++){
				sum+=b[k][g];
				}
			}
		cout<<sum<<endl;
	}
	return 0;
}
