#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		int b[n];
		int c[n];
		for(int j=0;j<n;j++){
			cin>>a[j];
			cin>>b[j];
			cin>>c[j];
		}
		int aa=0,suma=0;
		int bb=0,sumb=0;
		int cc=0,sumc=0;
		int xa[n],arra[n];
		int xb[n],arrb[n];
		int xc[n],arrc[n];
		for(int j=0;j<n;j++){
			int maxn=a[j];
			if(b[j]>maxn){
				maxn=b[j];
			}
			if(c[j]>maxn){
				maxn=c[j];
			}
			if(a[j]==maxn){
				aa+=a[j];
				xa[suma]=j;
				arra[suma]=a[j];
				suma++;
			}else if(b[j]==maxn){
				bb+=b[j];
				xb[sumb]=j;
				arrb[sumb]=b[j];
				sumb++;
			}else if(c[j]==maxn){
				cc+=c[j];
				xc[sumc]=j;
				arrc[sumc]=c[j];
				sumc++;
			}
		}
		while(suma>n/2||sumb<n/2||sumc<n/2){
		if(suma>n/2){
			int mix;
			if(arra[0]!=1e8){
				mix=arra[0];
			}else{
				mix=arra[1]
			}
			int s=0;
			for(int j=0;j<suma;j++){
				if(arra[j]<mix){
					mix=arra[j];
					s=j;
				}
			}
			for(int j=0;j<suma;j++){
				if(arra[j]==mix){
					int y=xa[s];
					int z=xa[j];
					if(b[z]>b[y]){
						s=j;
					}else if(c[z]>c[y]){
						s=j;
					}
				}
			}
				int p=xa[s];
				suma--;
				aa-=arra[s];
				arra[s]=1e8;
				xa[s]=1e8;
				if(b[p]>c[p]){
				bb+=b[p];
				xb[sumb]=p;
				arrb[sumb]=b[p];
				sumb++;
				}else{
				cc+=c[p];
				xc[sumc]=p;
				arrc[sumc]=c[p];
				sumc++;
				}
			
			
		}
		if(sumb>n/2){
		    int mix;
			if(arrb[0]!=1e8){
				mix=arrb[0];
			}else{
				mix=arrb[1]
			}
			int s=0;
			for(int j=0;j<sumb;j++){
				if(arrb[j]<mix){
					mix=arrb[j];
					s=j;
				}
			}
			for(int j=1;j<sumb;j++){
				if(arrb[j]==mix){
					int y=xb[s];
					int z=xb[j];
					if(a[z]>a[y]){
						s=j;
					}else if(c[z]>c[y]){
						s=j;
					}
				}
			}
				int p=xb[s];
				sumb--;
				bb-=b[p];
				arrb[s]=1e8;
				xb[s]=1e8;
				if(a[p]>c[p]){
				aa+=a[p];
				xa[suma]=p;
				arra[suma]=a[p];
				suma++;
				}else{
				cc+=c[p];
				xc[sumc]=p;
				arrc[sumc]=c[p];
				sumc++;
				}
			
			
		}if(sumc>n/2){
			int mix;
			if(arrc[0]!=1e8){
				mix=arrc[0];
			}else{
				mix=arrc[1]
			}
			int s=0;
			for(int j=0;j<sumc;j++){
				if(arrc[j]<mix){
					mix=arrc[j];
					s=j;
				}
			}
			for(int j=1;j<sumc;j++){
				if(arrc[j]==mix){
					int y=xc[s];
					int z=xc[j];
					if(a[z]>a[y]){
						s=j;
					}else if(b[z]>b[y]){
						s=j;
					}
				}
			}
				int p=xc[s];
				sumc--;
				cc-=arrc[s];
				arrc[s]=1e8;
				xc[s]=1e8;
				if(a[p]>b[p]){
				aa+=a[p];
				xa[suma]=p;
				arra[suma]=a[p];
				suma++;
				}else{
				bb+=b[p];
				xb[sumb]=p;
				arrb[sumb]=b[p];
				sumb++;
				}
		
			
		}
		}
		cout<<aa+bb+cc<<' ';
	}
	return 0;
}




