#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	int n,m,f[101],rn=0,rm=1,max,mi=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n*m;i++){
		max=0;
		for(int j=0;j<n*m;j++){
			if(f[j]>=max){
				max=f[j];
				mi=j;
			}
		}
		if(rm%2==0){
			rn--;
			if(rn==0){
				rn++;
				rm++;
			}
		}
		else{
			rn++;
			if(rn==n+1){
				rn--;
				rm++;
			}
		}
		if(max==f[0])
			break;
		f[mi]=0;
	}
	cout<<rm<<" "<<rn;
	return 0;
}
