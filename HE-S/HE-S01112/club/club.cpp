#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[100005][1005]={};
int P[MAXN]={};
int H[5]={};
double xl[MAXN]={};
int main(){
	freopean("club.in","r","stdin")
	freopean("club.out","w","stdout")
	int t,n,he=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		double X=0;
		for(int i=1;i<=n;i++){
			int ant=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]!=0)ant++;
			}
			double x=(a[i][1]+a[i][2]+a[i][3])/ant;
			for(int j=1;j<=3;j++){
				if(x>=a[i][j]){
					xl[j]=x-a[i][j];
				}else{
					xl[j]=a[i][j]-x;
				}
			}
			X=min(xl[1],min(xl[2],xl[3]));
			int Xx;
			for(int j=1;j<=3;j++){
				if(X==xl[j]){
					Xx=j;
				}
			}
			H[i]=a[i][Xx];
			he+=H[i];
		}
		cout<<he<<endl;
	}
	
	return 0;
}
