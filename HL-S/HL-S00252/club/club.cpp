#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","club.in",stdin);
	freopen("w","club.out",stdout);
	int t,n,a[10086],b[10086],c[10086],a_1[10086],b_1[10086],c_1[10086],g[10],flag=0,flag_1=0,total=0,totala=0,totalb=0,totalc=0;
	cin>>t;
	for(int i=0;i<t;i++){
		total=0,totala=0,totalb=0,totalc=0,a[10086]=0,b[10086]=0,c[10086]=0,a_1[10086]=0,b_1[10086]=0,c_1[10086]=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
			cin>>b[j];
			cin>>c[j];
		}
		for(int j=0;j<n;j++){
			flag=0,flag_1=0;
			for(int k=0;k<n;k++){
				if(a[k]>flag){
					flag=a[k];
				}
			}
			for(int k=0;k<n;k++){
				if(a[k]==flag){
					flag_1=k;
				}
			}
			a_1[j]=flag;
			a[flag_1]=0;
		}
		for(int j=0;j<n;j++){
			flag=0,flag_1=0;
			for(int k=0;k<n;k++){
				if(b[k]>flag){
					flag=b[k];
				}
			}
			for(int k=0;k<n;k++){
				if(b[k]==flag){
					flag_1=k;
				}
			}
			b_1[j]=flag;
			b[flag_1]=0;
		}
		for(int j=0;j<n;j++){
			flag=0,flag_1=0;
			for(int k=0;k<n;k++){
				if(c[k]>flag){
					flag=c[k];
				}
			}
			for(int k=0;k<n;k++){
				if(c[k]==flag){
					flag_1=k;
				}
			}
			c_1[j]=flag;
			c[flag_1]=0;
		}
		for(int j=0;j<n/2;j++){
			totala+=a_1[j];
			totalb+=b_1[j];
			totalc+=c_1[j];
		}
		if(totala+totalb>totalc){
			total=totala+totalb;
		}
		if(totala+totalc>totalb){
			total=totala+totalc;
		}
		if(totalb+totalc>totala){
			total=totalb+totalc;
		}
		g[t]=total;
	}
	for(int i=0;i<t;i++){
		cout<<g[t]<<endl;
	}
	return 0;
}
