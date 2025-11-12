#include<bits/stdc++.h>
using namespace std;
int nn,mm,seat1[121]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>nn>>mm;
	int ii,jj,tt,wei,aa1,wai,wx,wy,zj;
	for(ii=1;ii<=nn*mm;ii++){
		cin>>seat1[ii];
	}
	wei=seat1[1];
	for(ii=1;ii<=nn*mm;ii++){
		for(jj=nn*mm;jj>ii;jj--){
			if(seat1[jj]>seat1[jj-1]){
				tt=seat1[jj];
				seat1[jj]=seat1[jj-1];
				seat1[jj-1]=tt;
			}
		}
	}
	for(ii=1;ii<=nn*mm;ii++){
		if(seat1[ii]==wei){
			wai=ii;
			break;
		}
	} 
	if(wai%nn!=0){
		wx=(wai/nn)+1;
	}
	else{
		wx=wai/nn;
	}
	if(wx%2==1){
		wy=wai%nn;
		if(wy==0)wy=nn;
	}
	else{
		zj=wai%nn;
		if(zj==0)zj=nn;
		wy=nn-zj+1;
	}
	cout<<wx<<' '<<wy;
	return 0;
} 
