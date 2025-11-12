#include<bits/stdc++.h>
using namespace std;
long long h[5005];
int a,b[5005];
void love(int u){
	int n=0,k=0;
	for(int j=0;j<u;j++){
		int g=u-j;
		for(int i=k;i<=a;i++){
			if(g==n){
				i++;
			}
			b[n]=h[i];
			if(i!=u){
				n++;
			}
		}		
	}

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;	
	for(int i=0;i<a;i++){
		cin>>h[i];
	}
	if(a<=3){
		int hhh=h[0],hhhh=h[0];
		for(int i=1;i<3;i++){
			hhhh+=h[i];
			if(h[i]>=hhh){
				hhh=h[i];
			}
		}
		if(hhhh>2*hhh){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(h,h+a);
	long long l=0,maxl;
	for(int i=3;i<=a;i++){
		love(i);
	}
	return 0;
} 
