#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int js=0,js2=0,js3=0;
	int n,t,afs=0,bfs=0,cfs=0;
	int gl1=0,gl2=0,gl3=0;
	cin>>t;
	int crusala[t]={};
	int crusalb[t]={};
	int crusalc[t]={};
	for(es=1;es<=t;es++){
		cin>>n;
		int acd[10]={},bcd[10]={},ccd[10]={};
		int pusi[10]={}, pusi2[10]={},pusi3[10]={},;
		int a[n+1]={};
		int b[n+1]={};
		int c[n+1]={};
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		acd[gl1]=a[1];
		do{
			if(gl1=0){
				for(int i=2;i<=n;i++){
					if(a[i]>acd[gl1]){
						acd[gl1]=a[i];
						pusi[gl1]++;
					}	
				}
				gl1++;
				continue;
			}
			acd[gl1]=acd[gl1-1]-1;
			for(int i=2;i<=n;i++){
				if(a[i]==acd[gl1]){
					acd[gl1]=a[i];
					pusi[gl1]++;
				}		
			}
			gl1++;
		}while(acd[gl1]!=0);
		bcd[gl2]=b[1];
		do{
			if(gl2=0){
				for(int i=2;i<=n;i++){
					if(b[i]>bcd[gl2]){
						bcd[gl2]=b[i];
						pusi2[gl2]++;
						}	
				}
				gl2++;
				continue;
			}
			bcd[gl2]=bcd[gl2-1]-1;
			for(int i=2;i<=n;i++){
				if(b[i]==bcd[gl2]){
					bcd[gl2]=b[i];
					pusi2[gl2]++;
				}	
			}
			gl2++;
		}while(bcd[gl2]!=0);
		ccd[gl3]=c[1];
		do{
			if(gl3=0){
				for(int i=2;i<=n;i++){
					if(c[i]>ccd[gl3]){
						ccd[gl3]=c[i];
						pusi3[gl3]++;
					}	
				}
				gl3++;
				continue;
			}
			ccd[gl3]=ccd[gl3-1]-1;
			for(int i=2;i<=n;i++){
				if(c[i]==ccd[gl3]){
					ccd[gl3]=c[i];
					pusi3[gl3]++;
				}	
			}
			gl3++;
		}while(ccd[gl3]!=0);
		for(int i=0;i<gl1;i++){
			if(js==n/2){
				crusala[es]=afs;
				break;
			}
			if(pusi[i]>1){
				js+=pusi[i];
				afs+=pusi[i]*acd[i];
				continue;
			}
			afs+=acd[i];
			js+=1;
		}
		for(int i=0;i<gl2;i++){
			if(js2==n/2){
				crusalb[es]=bfs;
				break;
			}
			if(pusi2[i]>1){
				js2+=pusi2[i];
				bfs+=pusi2[i]*bcd[i];
				continue;
			}
			bfs+=bcd[i];
			js2+=1;
		}
		for(int i=0;i<gl3;i++){
			if(js3==n/2){
				crusalc[es]=cfs;
				break;
			}
			if(pusi3[i]>1){
				js3+=pusi3[i];
				cfs+=pusi3[i]*ccd[i];
				continue;
			}
			cfs+=ccd[i];
			js3+=1;
		}	
	}
	for(int es=1;es<=t;es++){
		if(crusalc[es]>crusalb[es] && crusalc[es]>crusala[es] ){
			cout<<crusalc[es];
		}
		if(crusalb[es]>crusalc[es] && crusalb[es]>crusala[es]){
			cout<<crusalb[es];
		}
		if(crusala[es]>crusalb[es] && crusala[es]>crusalc[es]){
			cout<<crusala[es];
		}
		if(crusalc[es]==crusalb[es] && crusalc[es]>crusala[es] ){
			cout<<crusalc[es];
		}
		if(crusalc[es]==crusala[es] && crusalc[es]>crusalb[es]){
			cout<<crusalc[es];
		}
		if(crusalb[es]>crusalc[es] && crusalb[es]==crusala[es]){
			cout<<crusalb[es];
		}
	}
	return 0;

