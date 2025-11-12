#include<bits/stdc++.h>
using namespace std;
int n,k,l[500000],i,j,zd=0;
void dg(int wz,int k,int sl,int h,int cd){
	if(wz==cd&&h+l[wz]!=k&&h-l[wz]!=k&&l[wz]-h!=k){
		if(sl>zd){
			zd=sl;
		}return;
	}else if(wz==cd&&(h+l[wz]==k||h-l[wz]==k||l[wz]-h==k)){
		sl++;
		if(sl>zd){
			zd=sl;
		}return;
	}else if(h+l[wz]==k||h-l[wz]==k||l[wz]-h==k){
		dg(wz+1,k,sl+1,0,cd);
	}else{
		dg(wz+1,k,0,0,cd);
		dg(wz+1,k,sl,h+l[wz],cd);
		dg(wz+1,k,sl,h-l[wz],cd);
		dg(wz+1,k,sl,l[wz]-h,cd);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>l[i];
		if(l[i]==k){
			j++;
		}
	}dg(0,k,0,0,n);
	cout<<zd;
	return 0;
}
