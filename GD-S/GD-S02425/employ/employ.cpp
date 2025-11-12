#include<bits/stdc++.h>
using namespace std;
int n,m,nx[10001],D=0,pt=1;
string nd;
bool sf[10001];
void f(int sx,int lqrs,int cyz){
	if(sx==n||lqrs>m){
		if(lqrs>=m){
			D++;
		}
		return;
	}else{
		sf[cyz]=false;
		if(nd[sx]==0){
			while(pt){
				for(int o=1;o<=n;o++){
					nx[o]--;
					if(nx[o]==0){
					pt++;
					}
				}
				pt--;
			}
			nx[sx]==0;
		}else{
			nx[sx]=n+1;
			lqrs++;
		}
		for(int g=1;g<=n;g++){
			if(!sf[g]){
				f(sx+1,lqrs,g);
			}
		}
		sf[cyz]=true;
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>nd;
	for(int i=1;i<=n;i++){
		cin>>nx[i];
		sf[i]=true;
	}
	for(int i=1;i<=n;i++){
		f(1,0,i);
	}
	cout<<D-1;
	return 0;
}
