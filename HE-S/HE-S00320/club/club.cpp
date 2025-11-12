#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	int n=0,t=0,m=1,j,i,m1=1,m2=1,m3=1,c=1,v=0;
	int bm=0,bm1=0,bm2=0,bm3=0;
	int zd=0;
	cin>>t;
	for(int y=1;y<=t;y++){
	for(i=1;i<=1;i++){
		cin>>n;
		for(j=1;j<=n;j++){
		for(int i=1;i<=t;i++){
			cin>>b[i]; 
		}
		zd=b[1];
		for(int p=1;p<=t;p++){
			if(zd<b[p+1]){
				zd=b[p+1]; 
			}else{
			}
		}
			if(zd==b[1]){
				bm1++;
			}
			if(zd==b[2]){
				bm2++;
			}
			if(zd==b[3]){
				bm3++;
			}
			zd=0;
	}
	bm=(bm1+bm2+bm3)-bm;
	a[c]=bm;
	c++;
	int bm=0,bm1=0,bm2=0,bm3=0;
	}
}
for(int i=1;i<=t;i++){
	v=a[i]+7*(4-2*i);
	if(v<0){
		v+=(n+1)*7;
	}
		cout<<v<<endl;
		
	}
return 0;
} 
