#include<bits/stdc++.h>
using namespace std;
long long t=0;
struct l{
	int k1;
	int k2;
	int k3;
}d[20005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n=0,cnt=0,aw=0,bw=0,cw=0,px=0,py=0,pz=0;
		int f1[20005]={0};
		int f2[20005]={0};		
		int f3[20005]={0};		
		cin>>n;										
		for(int j=1;j<=n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			d[j].k1=x;
			d[j].k2=y;
			d[j].k3=z;
			int mx=max(x,max(y,z));
			int mn=min(x,min(y,z));
			int md=x+y+z-mx-mn;			
			if(mx==x){
				aw+=x;
				px++;
				f1[mx-md]++;}
			else if(mx==y){
				bw+=y;
				py++;
				f2[mx-md]++;}
			else{
				cw+=z;
				pz++;
				f3[mx-md]++;}
			cnt=aw+bw+cw;}
			int p=n/2;
			if(px>p){
				for(int j=1;j<=20000;j++){
					if(f1[j]>0){
		//			cout<<cnt<<" "<<f1[j]<<" "<<pz<<" ";	
					if((px-f1[j])>p) cnt=cnt-f1[j]*j;
					else {cnt=cnt-j*(px-p); break;}
	//				cout<<cnt;
					px=px-f1[j];
					}}
			}
			if(py>p){
				for(int j=1;j<=20000;j++){
					if(f2[j]>0){
	//				cout<<cnt<<" "<<f2[j]<<" "<<pz<<" ";												
					if((py-f2[j])>p) cnt=cnt-f2[j]*j;
					else {cnt=cnt-j*(py-p); break;}
					py=py-f2[j];
	//				cout<<cnt;
					}}
			}
			if(pz>p){
				for(int j=1;j<=20000;j++){
					if(f3[j]>0){
		//			cout<<cnt<<" "<<f3[j]<<" "<<pz<<" ";												
					if((pz-f3[j])>p) cnt=cnt-f3[j]*j;
					else {cnt=cnt-j*(pz-p); break;}
					pz=pz-f3[j];
		//			cout<<cnt;
					}}
			}
			cout<<cnt<<endl;}							
	return 0;}
